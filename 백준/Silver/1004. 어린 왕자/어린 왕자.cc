#include <iostream>
//#include <cmath>
using namespace std;
#define Pow(x) ((x)*(x))
int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;

    while(t--)
    {
        int x1,y1,x2,y2,n,ans=0;
        cin>>x1>>y1>>x2>>y2>>n;

        while(n--)
        {
            int cx,cy,r;
            cin>>cx>>cy>>r;
            if( ( Pow(cx-x1) + Pow(cy-y1) < Pow(r) ) ^ ( Pow(cx-x2) + Pow(cy-y2) < Pow(r) ) ) ans++;
        }

        cout<<ans<<'\n';
    }

    return 0;
}