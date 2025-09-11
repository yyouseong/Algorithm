#include <cstdio>
#include <vector>
#include <queue>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
bool desti[5001];
int chk[5001];
int BFS(queue<int>q, queue<int>cnt, vector<vector<int> >& route)
{
	while (!q.empty())
	{
		int bus = q.front();
		int c = cnt.front();
		q.pop();
		cnt.pop();
		if (desti[bus]) return c;
		for (int i = 0; i < route[bus].size(); i++)
		{
			int t = route[bus][i];
			if (chk[t] == 0)
			{
				chk[t] = 1;
				q.push(t);
				cnt.push(c + 1);
			}
		}
	}
}
int main()
{
	int n, m, k, x1, x2, y1, y2;
	scanf("%d%d%d", &n, &m, &k);
	vector<vector<int> > bus1(4), bus2(4), route(k + 1);
	queue<int> q, cnt;
	for (int i = 0; i < k; i++)
	{
		int a, b, c, d, e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		if (b == d)
		{
			bus1[0].push_back(b);
			bus1[1].push_back(Min(c, e));
			bus1[2].push_back(Max(c, e));
			bus1[3].push_back(a);
		}
		else
		{
			bus2[0].push_back(c);
			bus2[1].push_back(Min(b, d));
			bus2[2].push_back(Max(b, d));
			bus2[3].push_back(a);
		}
	}
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	for (int i = 0; i < bus1[0].size(); i++)
	{
		if (bus1[0][i] == x1 && bus1[1][i] <= y1 && y1 <= bus1[2][i])
		{
			q.push(bus1[3][i]);
			chk[bus1[3][i]] = 1;
			cnt.push(1);
		}
		if (bus1[0][i] == x2 && bus1[1][i] <= y2 && y2 <= bus1[2][i]) desti[bus1[3][i]] = 1;
	}
	for (int i = 0; i < bus2[0].size(); i++)
	{
		if (bus2[0][i] == y1 && bus2[1][i] <= x1 && x1 <= bus2[2][i])
		{
			q.push(bus2[3][i]);
			chk[bus2[3][i]] = 1;
			cnt.push(1);
		}
		if (bus2[0][i] == y2 && bus2[1][i] <= x2 && x2 <= bus2[2][i]) desti[bus2[3][i]] = 1;
	}
	for (int i = 0; i < bus1[0].size(); i++)
	{
		for (int j = 0; j < bus2[0].size(); j++)
		{
			if (bus1[1][i] <= bus2[0][j] && bus2[0][j] <= bus1[2][i] && bus2[1][j] <= bus1[0][i] && bus1[0][i] <= bus2[2][j])
			{
				route[bus1[3][i]].push_back(bus2[3][j]);
				route[bus2[3][j]].push_back(bus1[3][i]);
			}
		}
	}
	for (int i = 0; i < bus1[0].size(); i++)
	{
		for (int j = i + 1; j < bus1[0].size(); j++)
		{
			if (bus1[0][i] == bus1[0][j] && (((bus1[2][i] >= bus1[2][j]) && (bus1[2][j] >= bus1[1][i])) || ((bus1[2][i] <= bus1[2][j]) && (bus1[2][i] >= bus1[1][j]))))
			{
				route[bus1[3][i]].push_back(bus1[3][j]);
				route[bus1[3][j]].push_back(bus1[3][i]);
			}
		}
	}
	for (int i = 0; i < bus2[0].size(); i++)
	{
		for (int j = i + 1; j < bus2[0].size(); j++)
		{
			if (bus2[0][i] == bus2[0][j] && (((bus2[2][i] >= bus2[2][j]) && (bus2[2][j] >= bus2[1][i])) || ((bus2[2][i] <= bus2[2][j]) && (bus2[2][i] >= bus2[1][j]))))
			{
				route[bus2[3][i]].push_back(bus2[3][j]);
				route[bus2[3][j]].push_back(bus2[3][i]);
			}
		}
	}
	printf("%d\n", BFS(q, cnt, route));
	return 0;
}