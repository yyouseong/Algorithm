#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> paper(n, vector<int>(m));
    for (vector<int> &i : paper)
        for (int &j : i)
            cin >> j;

    int ans = 0;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
                cnt += paper[i + k][j];
            if (cnt > ans)
                ans = cnt;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 3; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
                cnt += paper[i][j + k];
            if (cnt > ans)
                ans = cnt;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    cnt += paper[i + k][j + l];
            if (cnt > ans)
                ans = cnt;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            int cnt = paper[i][j + 1] + paper[i + 1][j + 1];
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    int a = paper[i + l][j] + paper[i + k][j + 2];
                    if (cnt + a > ans)
                        ans = cnt + a;
                }
            }
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            int cnt = paper[i + 1][j] + paper[i + 1][j + 1];
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    int a = paper[i][j + l] + paper[i + 2][j + k];
                    if (cnt + a > ans)
                        ans = cnt + a;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            for (int y = 0; y < 2; y++)
            {
                int cnt = 0;
                for (int x = 0; x < 3; x++)
                    cnt += paper[i + y][j + x];
                for (int k = 0; k < 3; k++)
                    if (paper[i + 1 - y][j + k] + cnt > ans)
                        ans = cnt + paper[i + 1 - y][j + k];
            }
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            for (int y = 0; y < 2; y++)
            {
                int cnt = 0;
                for (int x = 0; x < 3; x++)
                    cnt += paper[i + x][j + y];
                for (int k = 0; k < 3; k++)
                    if (paper[i + k][j + 1 - y] + cnt > ans)
                        ans = cnt + paper[i + k][j + 1 - y];
            }
        }
    }
    cout << ans;
    return 0;
}