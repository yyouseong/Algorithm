#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int teamStatus(vector<vector<int>> &status,int k){
    vector<int> team;
    for(int i=0;i<status.size();i++)
        if(k &(1<<i)) team.push_back(i);

    int stat = 0;
    for(int i=0;i<team.size();i++)
        for(int j=0;j<team.size();j++)
            stat += status[team[i]][team[j]];
    return stat;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> status(n, vector<int>(n));
    for (vector<int> &i : status)
        for (int &j : i)
            cin >> j;
    int N = (1 << n) - 1, ans = 2100000000;
    for (int i = 1; i < N; i++)
    {
        int cnt = abs(teamStatus(status,i) - teamStatus(status,N^i));
        if(ans > cnt) ans = cnt;
    }
    cout<<ans;
    return 0;
}