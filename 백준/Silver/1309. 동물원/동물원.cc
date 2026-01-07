#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 9901
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] * 2) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    cout << (dp[n][0] + 2 * dp[n][1]) % MOD;
    return 0;
}