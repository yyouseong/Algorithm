#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, maxN = -100000000, less = 0;
    cin >> n;
    vector<int> dp(n + 1, 0), arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] > dp[i - 1] + arr[i])
        {
            dp[i] = arr[i];
            less = 0;
        }
        else
        {
            dp[i] = arr[i] + dp[i - 1];
            maxN = max(maxN, dp[i] - less);
            if (arr[i] < 0)
                less = min(arr[i], less);
        }
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxN = max(maxN, dp[i]);
    }
    int i = 1, maxN2 = -1000, j = n;
    while (i <= n && arr[i] <= 0)
        i++;
    while (j >= 0 && arr[j] <= 0)
        j--;
    vector<int> brr(1, 0);
    queue<int> q;
    for (; i <= j; i++)
    {
        if (arr[i] < 0)
        {
            if (brr.back() - arr[i] < 0)
            {
                while (!q.empty())
                {
                    maxN2 = max(maxN2, brr.back() - q.front());
                    q.pop();
                }
                brr.push_back(0);
            }
            else
            {
                brr.back() += arr[i];
                q.push(arr[i]);
            }
        }
        else
        {
            brr.back() += arr[i];
        }
    }
    while (!q.empty())
    {
        maxN2 = max(maxN2, brr.back() - q.front());
        q.pop();
    }

    /*for (int &i : brr)
        cout << i << ' ';
    cout << '\n';*/

    for (int i = 1; i < brr.size(); i++)
        maxN2 = max(maxN2, brr[i] + brr[i - 1]);
    cout << max(maxN, maxN2);
    return 0;
}