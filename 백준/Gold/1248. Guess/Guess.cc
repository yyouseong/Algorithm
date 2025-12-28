#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> matrix(10, vector<int>(10));
vector<int> integers(11), inx(11);

bool chk(int cur)
{
    for (int i = 0; i <= cur; i++)
    {
        if (matrix[i][cur] == 0 && integers[cur + 1] - integers[i] != 0)
            return false;
        if (matrix[i][cur] == 1 && integers[cur + 1] - integers[i] <= 0)
            return false;
        if (matrix[i][cur] == -1 && integers[cur + 1] - integers[i] >= 0)
            return false;
    }
    return true;
}

bool back(int cur, int end)
{
    if (cur == end)
        return true;
    for (int idx = -10; idx <= 10; idx++)
    {
        inx[cur] = idx;
        integers[cur + 1] = integers[cur] + idx;
        if (chk(cur))
        {
            if (back(cur + 1, end))
                return true;
        }
    }
    return false;
}

int main()
{
    int n;
    string str;
    cin >> n >> str;
    for (int i = 0, k = 0; i < n; i++)
    {
        for (int j = i; j < n; j++, k++)
        {
            if (str[k] == '0')
                matrix[i][j] = 0;
            if (str[k] == '+')
                matrix[i][j] = 1;
            if (str[k] == '-')
                matrix[i][j] = -1;
        }
    }

    back(0, n);
    for (int i =0;i<n;i++)
        cout << inx[i] << ' ';
    return 0;
}