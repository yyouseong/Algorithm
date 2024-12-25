#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double Vec_sum(vector<vector<int> >&VEC,int n, int idx, int half, int x_sum,int y_sum)
{
    if(idx == n) return sqrt(pow(x_sum,2)+pow(y_sum,2));

    double mini=10000000;
    if(n-idx-1 >= half)
    {
        mini = min(mini, Vec_sum(VEC,n,idx+1,half, x_sum+VEC[idx][0], y_sum+VEC[idx][1]));
    }
    if(half)
    {
        mini = min(mini, Vec_sum(VEC,n,idx+1,half-1, x_sum-VEC[idx][0], y_sum-VEC[idx][1]));
    }

    return mini;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(15);

    int t;
    vector<vector<int> > VEC(20,vector<int>(2));
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++) cin>>VEC[i][0]>>VEC[i][1];
        cout<<Vec_sum(VEC,n,0,n/2,0,0)<<'\n';

    }
}
