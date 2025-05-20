#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define N 2502
#define Min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
using namespace std;
LL P[N][N], ans;
int main()
{
	int n, m, max_fuel = 0;
	vector<int> Fuel;
	vector<pair<int, int> > Dis[N];
	priority_queue<pair<LL, pair<int, int>>>q;
	scanf("%d%d", &n, &m);
	Fuel.resize(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &Fuel[i]), max_fuel = max(max_fuel, Fuel[i]);
	for (int i = 0, a, b, c; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		Dis[a].push_back(make_pair(b, c));
		Dis[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= n; i++) for (int j = 0; j <= max_fuel; j++) P[i][j] = -1;
	q.push({ 0, { -Fuel[1], 1 } });
	while (!q.empty())
	{
		LL dis = -q.top().first;
		LL fuel = -q.top().second.first;
		LL city = q.top().second.second;
		q.pop();
		if (P[city][fuel] != -1) continue;
		P[city][fuel] = dis; 
		if (city == n)
		{
			ans = dis;
			break;
		}
		for (int i = 0; i < Dis[city].size(); i++)
		{
			int ct = Dis[city][i].first;
			LL dist = Dis[city][i].second;
			int f = Min(fuel, Fuel[ct]);
			/*if (P[ct][f] == -1) */q.push({ -dist * fuel - dis,{ -f, ct } });
		}
	}
	printf("%lld\n", ans);
	return 0;
}