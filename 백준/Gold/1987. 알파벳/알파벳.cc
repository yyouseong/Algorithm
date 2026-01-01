#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define Max(a, b) (a > b ? a : b)
using namespace std;

int r, c;
vector<string> M(30);
vector<bool> CHK(30);
int f(int x, int y)
{
    if (x < 0 || x == r || y < 0 || y == c || CHK[M[x][y] - 65])
        return 0;
    CHK[M[x][y] - 65] = true;
    int a = f(x + 1, y);
    int b = f(x - 1, y);
    int c = f(x, y + 1);
    int d = f(x, y - 1);
    int t = max(max(a, b), max(c, d));
    CHK[M[x][y] - 65] = false;
    return t + 1;
}

int main()
{
    cin >> r >> c;

    int maxN = 0;

    for (string &i : M)
        cin >> i;

    cout << f(0, 0);
    return 0;
}