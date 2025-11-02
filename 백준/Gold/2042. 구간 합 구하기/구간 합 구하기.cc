#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n;
vector<ll> arr;
vector<ll> tree;

ll sum(int idx)
{
    ll total = 0;
    while (idx > 0)
    {
        total += tree[idx];
        idx -= (idx & -idx);
    }
    return total;
}

void update(int idx, ll val)
{
    while (idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, k;
    cin >> n >> m >> k;
    arr.resize(n + 1);
    tree.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
    ll c;
    for (int i = 0, a, b; i < m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            ll diff = c - arr[b];
            arr[b] = c;
            update(b, diff);
        }
        else
            cout << sum(c) - sum(b - 1) << '\n';
    }
    return 0;
}