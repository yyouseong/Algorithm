#include <iostream>
#include <vector>
#define mod 1000000000
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> dp(10, vector<long long>(n + 1, 0));
    for (int i = 1; i < 10; i++)
        dp[i][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = dp[1][i - 1];
        dp[9][i] = dp[8][i - 1];
        for (int j = 1; j < 9; j++)
            dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % mod;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum = (sum + dp[i][n]) % mod;
    cout << sum;

    return 0;
}