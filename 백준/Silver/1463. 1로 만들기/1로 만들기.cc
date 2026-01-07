#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1000000);
    dp[n] = 0;
    for (int i = n; i > 1; i--)
    {
        if (i % 3 == 0)
            dp[i / 3] = min(dp[i] + 1, dp[i / 3]);
        if (i % 2 == 0)
            dp[i / 2] = min(dp[i] + 1, dp[i / 2]);
        dp[i - 1] = min(dp[i - 1], dp[i] + 1);
    }
    cout << dp[1];
    return 0;
}