#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int X[4] = { 1,-1,0,0 };
int Y[4] = { 0,0,1,-1 };
bool chk[102][102];
int main()
{
	int n, m, ans;
	int map[102][102];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	queue<pair<int, int> > q;
	q.push({ 0,1 });
	chk[0][0] = true;
	while (!q.empty())
	{
		int f = q.front().first;
		int s = q.front().second;
		int a = f / m;
		int b = f % m;
		if (a + 1 == n && b + 1 == m)
		{
			ans = s;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = a + X[i];
			int y = b + Y[i];
			if (x >= 0 && y >= 0 && x < n && y < m)
			{
				if (chk[x][y] == false && map[x][y] == true)
				{
					q.push({ x * m + y,s + 1 });
					chk[x][y] = true;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}