#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, maxN = -100000000;
    cin >> n;
    vector<int> dp(n + 1, 0);
    for (int i = 1, a; i <= n; i++)
    {
        cin >> a;
        dp[i] = max(dp[i - 1] + a, a);
        maxN = max(maxN, dp[i]);
    }
    cout << maxN;
    return 0;
}