#include <iostream>
#include <algorithm>
#include <vector>
#define MaxN 10001
using namespace std;

int CHKing(int enemy, int w, int bef, int aft)
{
    if(enemy <= w && bef > aft) return aft;
    else return bef;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    vector<vector<int> > CIR(MaxN,vector<int>(2,0));

    while(t--)
    {
        int n,w, ans = 200000;
        cin>>n>>w;
        for(int i=0;i<n;i++) cin>>CIR[i][0];
        for(int i=0;i<n;i++) cin>>CIR[i][1];

        vector<int>IN(n,n*2),OUT(n,n*2),BOTH(n,n*2);
        
        BOTH[0] = CIR[0][0]+CIR[0][1] > w ? 2:1;
        if(n > 1) BOTH[1] = CIR[0][0]+CIR[1][0] <= w && CIR[0][1]+CIR[1][1] <= w ? 2:4;
        OUT[0] = IN[0] = 1;
        for(int i=1;i<n;i++)
        {
            IN[i] = CHKing(CIR[i-1][0]+CIR[i][0], w, IN[i], OUT[i-1]+1);
            IN[i] = min(IN[i], BOTH[i-1]+1);

            OUT[i] = CHKing(CIR[i-1][1]+CIR[i][1], w, OUT[i], IN[i-1]+1);
            OUT[i] = min(OUT[i], BOTH[i-1]+1);

            if(i > 1 && CIR[i-1][0]+CIR[i][0] <= w && CIR[i-1][1]+CIR[i][1] <= w) BOTH[i] = min(BOTH[i], BOTH[i-2] + 2);
            BOTH[i] = CHKing(CIR[i][0]+CIR[i][1], w, BOTH[i], BOTH[i-1]+1);

            BOTH[i] = min(BOTH[i],IN[i]+1);
            BOTH[i] = min(BOTH[i],OUT[i]+1);
        }
        ans=min(ans,BOTH[n-1]);

        if(n > 1 && CIR[0][0]+CIR[n-1][0] <= w)
        {
            vector<int>IN(n,n*2),OUT(n,n*2),BOTH(n,n*2);
            BOTH[0] = 2;
            OUT[0] = 0;
            IN[0] = IN[n-1] = 1;
            for(int i=1;i<n;i++)
            {
                if(i < n-1)
                {
                    if(i > 1) IN[i] = CHKing(CIR[i-1][0]+CIR[i][0], w, IN[i], OUT[i-1]+1);
                    IN[i] = min(IN[i], BOTH[i-1]+1);
                }

                OUT[i] = CHKing(CIR[i-1][1]+CIR[i][1], w, OUT[i], IN[i-1]+1);
                OUT[i] = min(OUT[i], BOTH[i-1]+1);

                if(i < n-1)
                {
                    if(i > 1 && CIR[i-1][0]+CIR[i][0] <= w && CIR[i-1][1]+CIR[i][1] <= w) BOTH[i] = min(BOTH[i], BOTH[i-2] + 2);
                    BOTH[i] = CHKing(CIR[i][0]+CIR[i][1], w, BOTH[i], BOTH[i-1]+1);

                    BOTH[i] = min(BOTH[i],IN[i]+1);
                    BOTH[i] = min(BOTH[i],OUT[i]+1);
                }
            }
            ans=min(ans,OUT[n-1]);
        }
        if(n > 2 && CIR[0][1]+CIR[n-1][1] <= w)
        {
            vector<int>IN(n,n*2),OUT(n,n*2),BOTH(n,n*2);
            BOTH[0] = 2;
            OUT[0] = OUT[n-1] = 1;
            IN[0] = 0;
            for(int i=1;i<n;i++)
            {
                IN[i] = CHKing(CIR[i-1][0]+CIR[i][0], w, IN[i], OUT[i-1]+1);
                IN[i] = min(IN[i], BOTH[i-1]+1);
                
                if(i < n-1)
                {
                    if(i > 1) OUT[i] = CHKing(CIR[i-1][1]+CIR[i][1], w, OUT[i], IN[i-1]+1);
                    OUT[i] = min(OUT[i], BOTH[i-1]+1);
                }

                if(i < n-1)
                {
                    if(i > 1 && CIR[i-1][0]+CIR[i][0] <= w && CIR[i-1][1]+CIR[i][1] <= w) BOTH[i] = min(BOTH[i], BOTH[i-2] + 2);
                    BOTH[i] = CHKing(CIR[i][0]+CIR[i][1], w, BOTH[i], BOTH[i-1]+1);//,cout<<"asdf\n";

                    BOTH[i] = min(BOTH[i],IN[i]+1);
                    BOTH[i] = min(BOTH[i],OUT[i]+1);
                }
            }
            ans=min(ans,IN[n-1]);
        }
        if(n > 1 && CIR[0][1]+CIR[n-1][1] <= w && CIR[0][0]+CIR[n-1][0] <= w)
        {
            vector<int>IN(n,n*2),OUT(n,n*2),BOTH(n,n*2);
            BOTH[0] = 2;
            OUT[0] = IN[0] = 0;
            for(int i=1;i<n;i++)
            {
                if(i > 1) IN[i] = CHKing(CIR[i-1][0]+CIR[i][0], w, IN[i], OUT[i-1]+1);
                IN[i] = min(IN[i], BOTH[i-1]+1);
                
                if(i > 1) OUT[i] = CHKing(CIR[i-1][1]+CIR[i][1], w, OUT[i], IN[i-1]+1);
                OUT[i] = min(OUT[i], BOTH[i-1]+1);

                if(i < n-1)
                {
                    if(i > 1)
                    {
                        if(CIR[i-1][0]+CIR[i][0] <= w && CIR[i-1][1]+CIR[i][1] <= w) BOTH[i] = min(BOTH[i], BOTH[i-2] + 2);
                    }
                    BOTH[i] = min(BOTH[i],IN[i]+1);
                    BOTH[i] = min(BOTH[i],OUT[i]+1);
                    BOTH[i] = CHKing(CIR[i][0]+CIR[i][1], w, BOTH[i], BOTH[i-1]+1);
                }
            }
            ans=min(ans,BOTH[n-2]);
        }
        cout<<ans<<'\n';
    }
}