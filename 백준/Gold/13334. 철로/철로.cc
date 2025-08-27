#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;

    cin >> n;
    vector<pair<int, int>> ho(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ho[i].first >> ho[i].second;
        if (ho[i].first < ho[i].second)
            swap(ho[i].first, ho[i].second);
    }
    cin >> d;

    sort(ho.begin(), ho.end());

    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (ho[i].first - ho[i].second <= d)
            pq.push(ho[i].second);

        while (pq.size())
        {
            if (ho[i].first - d > pq.top())
                pq.pop();
            else
                break;
        }
        ans = max(ans, (int)pq.size());
    }

    cout << ans;
    return 0;
}