#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll euclidean(ll a,ll b)
{
    if(b == 0) return a;
    return euclidean(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll>X(n),Y(n);
    for(ll &i:X)
        cin>>i;
    for(ll &i:Y)
        cin>>i;
        
    int cnt = 1,maxCnt = 1;
    ll x=X[0],y=Y[0],a,b, maxX=X[0],maxY=Y[0];
    for(int i=1;i<n;i++)
    {
        a=X[i]+x;
        b=Y[i]+y;

        ll gcd4 = euclidean(a,b);
        ll gcd3 = euclidean(X[i],Y[i]);
        if((b/gcd4)*(X[i]/gcd3) < (Y[i]/gcd3)*(a/gcd4))
        {
            x = y = cnt = 0;
        }
        x += X[i];
        y += Y[i];
        cnt++;
        
        ll gcd2 = euclidean(x,y);
        ll gcd1 = euclidean(maxX,maxY);
        ll fr = (maxY/gcd1)*(x/gcd2);
        ll bk = (maxX/gcd1)*(y/gcd2);
        if(fr < bk || fr == bk && cnt > maxCnt)
        {
            maxX=x/gcd2;
            maxY=y/gcd2;
            maxCnt=cnt;
        }
    }

    ll gcd = euclidean(maxX,maxY);
    ll ansX = maxX / gcd;
    ll ansY = maxY / gcd;

    cout<<ansY<<' '<<ansX<<'\n'<<maxCnt;
    
    return 0;
}