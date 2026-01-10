#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define MP std::make_pair
#define INF 2100000000
std::vector<std::pair<int, int> > city[1001];
std::priority_queue<std::pair<int, int> > q;
bool chk[1001];
int cost[1001];
int main()
{
	int n, m, st, en;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		city[a].push_back(MP(b, c));
		//city[b].push_back(MP(a, c));
	}
	scanf("%d%d", &st, &en);
	for (int i = 1; i <= n; i++) cost[i] = INF;
	cost[st] = 0;
	q.push(MP(0, st));
	while (!q.empty())
	{
		int x, y;
		x = -q.top().first;
		y = q.top().second;
		//printf("%d\n", y);
		q.pop();
		if (!chk[y])
		{
			chk[y] = 1;
			for (int i = 0; i < city[y].size(); i++)
			{
				int a = city[y][i].first;
				if (!chk[a])
				{
					cost[a] = std::min(city[y][i].second + x, cost[a]);
					q.push(MP(-cost[a], a));
				}
			}
		}
	}
	//for (int i = 1; i <= n; i++) printf("%d : %2d\n", i, cost[i]);
	printf("%d\n", cost[en]);
	return 0;
}