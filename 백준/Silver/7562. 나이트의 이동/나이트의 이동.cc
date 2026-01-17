#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct T { int x, y, k; };
int X[8] = { 2,1,-2,-1,-1,2,1,-2 };
int Y[8] = { -1,2,1,-2,2,1,-2,-1 };
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, x, y, a, b;
		scanf("%d%d%d%d%d", &n, &x, &y, &a, &b);
		vector<vector<int> > map(n + 1, vector<int>(n + 1, 0));
		queue<T> q;
		map[x][y] = 1;
		q.push({ x,y,0 });
		while (!q.empty())
		{
			int c = q.front().x;
			int d = q.front().y;
			int k = q.front().k;
			q.pop();
			if (c == a && d == b)
			{
				printf("%d\n", k);
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				int x1 = c + X[i];
				int y1 = d + Y[i];
				if ((0 <= x1 && x1 < n) && (0 <= y1 && y1 < n))
				{
					if (map[x1][y1] == 0)
					{
						map[x1][y1] = 1;
						q.push({ x1,y1, k + 1 });
					}
				}
			}
		}
	}
	return 0;
}