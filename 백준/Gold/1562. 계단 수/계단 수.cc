#include <cstdio>
#include <vector>
#define MOD 1000000000

using namespace std;

int main()
{
    int n;
    vector<vector<vector<int> > > STAIR(101, vector<vector<int> >(10,vector<int>(1025, 0)));
    for(int i=0;i<10;i++) STAIR[1][i][ 1<<i ] = 1;
    scanf("%d",&n);

    for(int i=2;i<=n;i++){
        for(int j=0;j<9;j++) {
            for(int k=0;k<1024;k++){
                STAIR[i][j][ k | 1<<j ] = ( STAIR[i][j][ k | 1<<j ] + STAIR[i-1][j+1][k] ) % MOD;
            }
        }
        for(int j=1;j<10;j++) {
            for(int k=0;k<1024;k++){
                STAIR[i][j][ k | 1<<j ] = ( STAIR[i][j][ k | 1<<j ] + STAIR[i-1][j-1][k] ) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<10;i++) ans = ( ans + STAIR[n][i][1023] ) % MOD;
    printf("%d\n", ans);
}
