#include <stdio.h>
#include <utility>
#include <queue>
#define MP std::make_pair
int n[10][10], h;
std::pair<int, int> st[100];
bool clear;
void f(int inx)
{
	if (inx == h)
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) printf("%d ", n[i][j]);
			puts("");
		}
		clear = 1;
		return;
	}
	int x, y, chk[10] = { 0 };
	std::queue<int> q;
	x = st[inx].first;
	y = st[inx].second;
	for (int i = 0; i < 9; i++)
	{
		chk[n[x][i]]++;
		chk[n[i][y]]++;
	}
	int I, J;
	I = x - x % 3;
	J = y - y % 3;
	for (int i = I; i < I + 3; i++) {
		for (int j = J; j < J + 3; j++)
		{
			chk[n[i][j]]++;
		}
	}
	for (int i = 1; i <= 9; i++) if (!chk[i]) q.push(i);
	while (!q.empty())
	{
		n[x][y] = q.front();
		q.pop();
		f(inx + 1);
		if (clear) return;
	}
	n[x][y] = 0;
	return;
}
int main()
{
	for (int i = 0; i < 9; i++){
		for (int j = 0, a; j < 9; j++)
		{
			scanf("%d", &a);
			n[i][j] = a;
			if (!a) st[h++] = (MP(i, j));
		}
	}
	f(0);
	return 0;
}