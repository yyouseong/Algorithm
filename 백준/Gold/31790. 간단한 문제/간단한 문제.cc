#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vector<int> notused(p);
    for (int i = 0; i < p; i++)
        notused[i] = n / p + (n % p > i);

    int bef = 0;
    vector<int> limit(n / p + 2, p);
    limit.front() = 0;
    limit.back() = n % p;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t > bef + 1 || t < bef || t > n / p + (n % p != 0))
        {
            cout << "NO\n";
            return 0;
        }
        else
        {
            if (t != bef)
            {
                limit[t] += limit[bef];
                bef = t;
            }
            else if (limit[t] < 1)
            {
                cout << "NO\n";
                return 0;
            }
            limit[t]--;
        }
    }
    cout << "YES\n";
    return 0;
}