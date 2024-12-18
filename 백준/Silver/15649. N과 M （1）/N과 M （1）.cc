#include <iostream>
#include <vector>
using namespace std;

vector<bool> CHK(10);
vector<int> ANS(10);

void F(int n, int m, int cnt)
{
    if(m == 0) 
    {
        for(int i=0;i<cnt;i++) cout<<ANS[i]<<" ";
        cout<<"\n";
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(CHK[i] == 0)
        {
            ANS[cnt] = i;
            CHK[i] = 1;
            F(n,m-1,cnt+1);
            CHK[i] = 0;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    F(n,m,0);

    return 0;
}