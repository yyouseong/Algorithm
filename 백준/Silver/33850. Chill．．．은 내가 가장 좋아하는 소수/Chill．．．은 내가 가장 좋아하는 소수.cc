#include <iostream>
#include <vector>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
const int MaxP = 200000;
vector<bool>chk(MaxP + 1,true);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<int> > tile(2,vector<int>(n+1));
    for(int i = 1;i <= n;i++) cin>>tile[0][i];
    for(int i = 1;i <= n;i++) cin>>tile[1][i];

    chk[1] = 0;
    for(int i=2;i*i<=MaxP;i++){
        if(chk[i] == 0) continue;
        for(int j=i*i;j<=MaxP;j += i)
            chk[j] = false;
    }
    
    vector<int> dp(n+1,0);
    dp[1] = chk[tile[0][1]+tile[1][1]]?a:b;
    
    for(int i=2;i<=n;i++)
    {
        int x = chk[tile[0][i-1]+tile[0][i]]?a:b;
        int y = chk[tile[1][i-1]+tile[1][i]]?a:b;
        int z = chk[tile[0][i]+tile[1][i]]?a:b;
        dp[i] = Max(dp[i-1] + z,dp[i-2] + x + y);
    }
    cout<<dp[n];
    return 0;
}
