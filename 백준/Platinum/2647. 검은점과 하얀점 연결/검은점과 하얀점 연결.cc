#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define N 101
#define INF 2e9
#define Max(a,b) (a)>(b)?(a):(b)
#define Min(a,b) (a)<(b)?(a):(b)

using namespace std;

struct Pair { int a, b, c; };

int Linked[N][N], L[N][N];
int n;
Pair Connect[N][N];
priority_queue<pair<int, int> > Q;

void f(int f, int b)
{
	L[f][b] = INF;
	if (f > 0 && b <= n)
	{
		if (Linked[f][b])
		{
			int T = L[f + 1][b - 1] + (b - f + 2 * Linked[f + 1][b - 1]);
			if (L[f][b] > T)
			{
				L[f][b] = T;
				Linked[f][b] = Linked[f + 1][b - 1] + 1;
				Connect[f][b] = { 0,f + 1,b - 1 };
			}//L[f][b] = Min(L[f][b], L[f + 1][b - 1] + (b - f + 2 * Linked[f + 1][b - 1]));
		}
		for (int i = f + 1; i < b - 1; i++)
		{
			if (f > 0 && b <= n)
			{
				if (Linked[f][i] && Linked[i + 1][b])
				{
					int T = L[f][i] + L[i + 1][b];
					if (L[f][b] > T)
					{
						L[f][b] = T;
						Linked[f][b] = Max(Linked[f][i], Linked[i + 1][b]);
						Connect[f][b] = { f,i,b };
					}//L[f][b] = Min(L[f][b], L[f][i] + L[i + 1][b]);
				}
			}
		}
	}
	if (INF == L[f][b]) L[f][b] = 0;
	return;
}
void Con(int i,int j)
{
	int a, b, c;
	a = Connect[i][j].a;
	b = Connect[i][j].b;
	c = Connect[i][j].c;
	if (j - i == 1)
	{
		Q.push({ -i,-j });
		return;
	}
	if (a)
	{
		Con(a, b);
		Con(b + 1, c);
	}
	else
	{
		Q.push({ -b + 1,-c - 1 });
		Con(b, c);
	}
}
int main()
{
	char BW[N];
	scanf("%d %s", &n, BW + 1);
	for (int i = 1; i < n; i++) if (BW[i] != BW[i + 1]) L[i][i + 1] = 3;
	for (int i = 1; i <= n; i++)
	{
		int S[2] = { 0 };
		for (int j = i; j <= n; j++)
		{
			S[BW[j] - 48]++;
			if (BW[j] != BW[i] && S[0] == S[1]) Linked[i][j] = 2;
		}
	}
	for (int j = 3; j < n; j++) for (int i = 1; i <= n - j; i++) f(i, i + j);
	Con(1, n);
	printf("%d\n", L[1][n]);
	{
		int i = n / 2;
		while (i--)
		{
			printf("%d %d\n", -Q.top().first, -Q.top().second);
			Q.pop();
		}
	}
	return 0;
}