#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int n, m, mini = 11;
vector<string> board(10);
stack<pair<int, int>> be, af, beo;
stack<char> bec;
bool move(int x, int y, int i, int j)
{
    int a = 0, b = 0;
    while (board[i + a + x][j + b + y] == '.' || board[i + a + x][j + b + y] == 'O')
    {
        a += x;
        b += y;
        if (board[i + a][j + b] == 'O')
        {
            bec.push(board[i][j]);
            board[i][j] = '.';
            beo.push({i, j});
            return true;
        }
    }

    be.push({i, j});
    af.push({i + a, j + b});
    swap(board[i][j], board[i + a][j + b]);
    return false;
}
void f(int cnt)
{
    if (cnt == 11)
        return;
    // cout << cnt << '\n';
    bool r = false, b = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
                r = move(-1, 0, i, j);
            if (board[i][j] == 'B')
                b = move(-1, 0, i, j);
        }
    }
    if (r && !b)
        mini = min(mini, cnt);
    if (!r && !b)
        f(cnt + 1);
    if (!r)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    if (!b)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    r = false, b = false;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'R')
                r = move(1, 0, i, j);
            if (board[i][j] == 'B')
                b = move(1, 0, i, j);
        }
    }
    if (r && !b)
        mini = min(mini, cnt);
    if (!r && !b)
        f(cnt + 1);
    if (!r)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    if (!b)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    r = false, b = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[j][i] == 'R')
                r = move(0, -1, j, i);
            if (board[j][i] == 'B')
                b = move(0, -1, j, i);
        }
    }
    if (r && !b)
        mini = min(mini, cnt);
    if (!r && !b)
        f(cnt + 1);
    if (!r)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    if (!b)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    r = false, b = false;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[j][i] == 'R')
                r = move(0, 1, j, i);
            if (board[j][i] == 'B')
                b = move(0, 1, j, i);
        }
    }
    if (r && !b)
        mini = min(mini, cnt);
    if (!r && !b)
        f(cnt + 1);
    if (!r)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    if (!b)
    {
        swap(board[be.top().first][be.top().second], board[af.top().first][af.top().second]);
        be.pop();
        af.pop();
    }
    else
    {
        board[beo.top().first][beo.top().second] = bec.top();
        beo.pop();
        bec.pop();
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    f(1);
    if (mini == 11)
        cout << -1;
    else
        cout << mini;
    return 0;
}