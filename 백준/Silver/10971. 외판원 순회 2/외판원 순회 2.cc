#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> city(10, vector<int>(10));
int f(int start, vector<bool> &chk, int cnt, int bef)
{
    if (cnt == n)
    {
        if (city[bef][start])
            return city[bef][start];
        else
            return 1000000000;
    }

    int ans = 2100000000;
    for (int i = 0; i < n; i++)
    {
        if (chk[i] == false && city[bef][i])
        {
            chk[i] = true;
            int tmp = f(start, chk, cnt + 1, i) + city[bef][i];
            if (ans > tmp)
                ans = tmp;
            chk[i] = false;
        }
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> city[i][j];

    int ans = 2100000000;
    vector<bool> chk(n, false);
    for (int i = 0; i < n; i++)
    {
        chk[i] = true;
        int a = f(i, chk, 1, i);
        chk[i] = false;
        if (ans > a)
            ans = a;
    }

    cout << ans;
    return 0;
}