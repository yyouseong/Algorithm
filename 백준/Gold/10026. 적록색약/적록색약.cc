#include <iostream>
#include <vector>
#include <string>
using namespace std;
int chk[102][102];
void DFS(vector<string>& col, int x, int y, int n, char color)
{
	if (x < 0 || y < 0 || x == n || y == n || chk[x][y] == 1 || color != col[x][y]) return;
	chk[x][y] = 1;
	DFS(col, x + 1, y, n, color);
	DFS(col, x - 1, y, n, color);
	DFS(col, x, y + 1, n, color);
	DFS(col, x, y - 1, n, color);
}
void dFS(vector<string>& col, int x, int y, int n, char color)
{
	if (x < 0 || y < 0 || x == n || y == n || chk[x][y] == 2) return;
	if (color != col[x][y] && (color == 'B' || col[x][y] == 'B')) return;
	chk[x][y] = 2;
	dFS(col, x + 1, y, n, color);
	dFS(col, x - 1, y, n, color);
	dFS(col, x, y + 1, n, color);
	dFS(col, x, y - 1, n, color);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, a = 0, b = 0;
	cin >> n;
	vector<string> col(n);
	for (int i = 0; i < n; i++) cin >> col[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (chk[i][j] == 0)
			{
				a++;
				DFS(col, i, j, n, col[i][j]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (chk[i][j] == 1)
			{
				b++;
				dFS(col, i, j, n, col[i][j]);
			}
		}
	}
	cout << a << ' ' << b << '\n';
	return 0;
}