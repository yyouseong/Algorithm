#include <iostream>
#include <vector>
using namespace std;

void update(vector<int> &tree, int node, int start, int end, int idx, int diff)
{
    if (idx < start || end < idx)
        return;
    tree[node] += diff;
    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, idx, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}
long long sum(vector<int> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(1000001), B(n), tree(4 * n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A[a] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        B[i] = A[a];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = B[i];
        ans += sum(tree, 1, 0, n - 1, j + 1, n - 1);
        update(tree, 1, 0, n - 1, j, 1);
    }
    cout << ans;
    return 0;
}