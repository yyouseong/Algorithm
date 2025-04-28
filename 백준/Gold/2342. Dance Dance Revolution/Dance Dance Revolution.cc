#include <iostream>
#include <vector>
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int MaxN = 100001;
const int MaxV = 2100000000;
const int Move[5][5]={{1,2,2,2,2},{2,1,3,4,3},{2,3,1,3,4},{2,4,3,1,3},{2,3,4,3,1}};

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> L_foot(MaxN,0),R_foot(MaxN,0),DP(MaxN);
    vector<vector<vector<int> > > DDR(MaxN,vector<vector<int> >(5,vector<int>(5,MaxV)));

    int num, idx = 1;
    cin >> num;
    DDR[1][0][num] = 2;
    while(num)
    {
        idx++;
        cin >> num;
        if(num == 0) break;

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(DDR[idx-1][i][j])
                {
                    DDR[idx][i][num] = Min(DDR[idx][i][num],DDR[idx-1][i][j] + Move[j][num]);
                    DDR[idx][num][j] = Min(DDR[idx][num][j],DDR[idx-1][i][j] + Move[i][num]);
                }
            }
        }
    }

    int lessMove = MaxV;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            lessMove = Min(lessMove, DDR[idx-1][i][j]);

    cout<<lessMove;
    return 0;
}