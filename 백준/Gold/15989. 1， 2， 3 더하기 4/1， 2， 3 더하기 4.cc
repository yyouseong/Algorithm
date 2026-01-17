#include <iostream>
#include <vector>
#define N 10001
using namespace std;

int main()
{
    vector<vector<int>> DP(3, vector<int>(N, 0));
    vector<int> ans(N);
    DP[2][3] = DP[1][2] = 1;
    for (int i = 1; i < N; i++)
        DP[0][i] = 1;
    for (int i = 3; i < N; i++)
        DP[1][i] = DP[1][i - 2] + DP[0][i - 2];
    for (int i = 4; i < N; i++)
        DP[2][i] = DP[2][i - 3] + DP[1][i - 3] + DP[0][i - 3];
    for (int i = 1; i < N; i++)
        ans[i] = DP[0][i] + DP[1][i] + DP[2][i];
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
}