#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 1000001;
vector<vector<int>> tree(maxN, vector<int>()), dp(2, vector<int>(maxN, 0));
vector<bool> visited(maxN,0);
void treeDp(int currentNode)
{
    dp[1][currentNode] = 1;
    visited[currentNode] = true;
    if (tree[currentNode].empty())
        return;

    for (int i = 0; i < tree[currentNode].size(); i++)
    {
        if(visited[tree[currentNode][i]] == 1) continue;
        treeDp(tree[currentNode][i]);
        dp[0][currentNode] += dp[1][tree[currentNode][i]];
        dp[1][currentNode] += min(dp[1][tree[currentNode][i]], dp[0][tree[currentNode][i]]);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    treeDp(1);

    cout << min(dp[0][1], dp[1][1]);
    return 0;
}