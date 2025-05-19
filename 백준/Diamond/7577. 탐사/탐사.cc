#include <cstdio>
#include <vector>
#include <algorithm>
#define Swap(a,b) do{int t=a;a=b;b=t;}while(0)
using namespace std;
typedef struct T { int x, y, z; };
int n, k;
char spc[45];
int chk[45];
vector < vector<pair<int, int> > > A(41), B(41);
vector<T>P;
bool CMP(T a, T b)
{
	int A = 1, B = 1, GA = a.y - a.x, GB = b.y - b.x;
	int CA = GA - a.z, CB = GB - b.z;
	if (a.z) A = -1;
	if (b.z) B = -1;
	if (CA * A == CB * B)
	{
		if (GA == GB) return a.x < b.x;
		return GA < GB;
	}
	return CA < CB;
}
bool CUT1(int t)
{
	if (A[t].size() > 0)
	{
		int& x = A[t][0].first;
		int& y = A[t][0].second;
		for (int i = 1; i < A[t].size(); i++)
		{
			int& a = A[t][i].first;
			int& b = A[t][i].second;
			if (x == a)
			{
				if (y == b) a = 0;
				else return false;
			}
			else
			{
				if (x > a) { Swap(x, a); Swap(y, b); }
				if (y > b) return false;
				else
				{
					A[x + 1].push_back({ a,b - y });
					a = 0;
				}
			}
		}
	}
	return true;
}
bool CUT2(int t)
{
	if (B[t].size() > 0)
	{
		int& x = B[t][0].first;
		int& y = B[t][0].second;
		for (int i = 1; i < B[t].size(); i++)
		{
			int& a = B[t][i].first;
			int& b = B[t][i].second;
			if (a == x)
			{
				if (y == b) a = 0;
				else return false;
			}
			else
			{
				if (x < a) { Swap(x, a); Swap(y, b); }
				if (y > b) return false;
				else
				{
					B[x - 1].push_back({ a,b - y });
					a = 0;
				}
			}
		}
	}
	return true;
}
bool f()
{
	for (int i = 1; i <= n; i++) if (CUT1(i) == 0) return false;
	for (int i = 1; i <= n; i++) for (int j = 0; j < A[i].size(); j++) if (A[i][j].first != 0) B[A[i][j].first].push_back({ i,A[i][j].second });
	for (int i = n; i >= 1; i--) if (CUT2(i) == 0) return false;
	for (int i = 1; i <= n; i++) for (int j = 0; j < B[i].size(); j++) if (B[i][j].first != 0) P.push_back({ B[i][j].first,i,B[i][j].second });
	for (int i = 0; i < P.size(); i++) if (P[i].z > P[i].y - P[i].x + 1) return false;
	sort(P.begin(), P.end(), CMP);
	return true;
}
bool PUT(int x, int s, int next)
{
	int X = x + 1;
	if (P.size() - 1 == x && s == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			if (spc[i] == '0') printf("-");
			else printf("%c", spc[i]);
		}
		return true;
	}

	if (s == 0)
	{
		for (int j = next; j <= P[x].y; j++)
		{
			if (x > chk[j] && chk[j] != -1) continue;
			chk[j] = x;
		}
		int S = P[X].z;
		for (int j = P[X].x; j <= P[X].y; j++) if (spc[j] == '#') S--;
		if (S >= 0)
		{
			bool t = PUT(X, S, P[X].x);
			if (t) return true;
		}
	}
	else
	{
		for (int i = next; i <= P[x].y - s + 1; i++)
		{
			if (spc[i] == '#' || spc[i] == '-' || (x > chk[i] && chk[i] != -1)) continue;
			spc[i] = '#';
			int t = PUT(x, s - 1, next + 1);
			if (t) return t;
			spc[i] = '0';
			chk[i] = x;
		}
	}
	return false;
}
bool back(int x)
{
	while (!P[x].z && x + 1 < P.size())
	{
		for (int i = P[x].x; i <= P[x].y; i++) spc[i] = '-';
		x++;
	}
	return PUT(x, P[x].z, P[x].x);
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) spc[i] = '0';
	for (int i = 1; i <= n; i++) chk[i] = -1;
	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		A[a].push_back({ b,c });
	}
	if (f())
	{
		if (back(0) == 0) printf("NONE\n");
	}
	else printf("NONE\n");
}