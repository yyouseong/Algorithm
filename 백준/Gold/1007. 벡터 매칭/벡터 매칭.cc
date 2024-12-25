#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define Min(a,b) ((a)<(b)?(a):(b))

double mini;
vector<bool> CHK(20);

double Vec_sum(vector<vector<int> >&VEC,int n)
{
    int x=0,y=0;

    for(int i=0;i<n;i++)
    {
        if(CHK[i])
        {
            x-=VEC[i][0];
            y-=VEC[i][1];
        }
        else
        {
            x+=VEC[i][0];
            y+=VEC[i][1];
        }
    }

    return sqrt(pow(x,2)+pow(y,2));
}

void Search(vector<vector<int> >&VEC,int n, int idx, int half)
{
    if(n-idx < half) return;
    if(half == 0) 
    {
        mini = min(mini, Vec_sum(VEC,n));
        return;
    }
    for(int i=idx; i<n;i++)
    {
        CHK[i] = 1;
        Search(VEC,n,i+1,half-1);
        CHK[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(7);

    int t;
    vector<vector<int> > VEC(20,vector<int>(2));
    cin>>t;
    
    while(t--)
    {
        int n;
        mini = 10000000;
        cin>>n;
        for(int i=0;i<n;i++) cin>>VEC[i][0]>>VEC[i][1];

        Search(VEC,n,0,n/2);
        cout<<mini<<'\n';
    }
}