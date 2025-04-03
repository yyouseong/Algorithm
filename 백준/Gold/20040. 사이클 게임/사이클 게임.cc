#include <iostream>
#include <vector>
using namespace std;

vector<int>U, Key;

int Root(int x)
{
    if(U[x] == x) return x;
    return U[x] = Root(U[x]);
}

int Union(int x, int y)
{
    int a = Root(x);
    int b = Root(y);

    if(a != b)
    {
        if(Key[a]<Key[b])
        {
            Key[b] += Key[a];
            Key[a] = Key[b];
            U[a] = b;
        }
        else
        {
            Key[a] += Key[b];
            Key[b] = Key[a];
            U[b] = a;
        }
        return false;
    }
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n,m;
    int answer = 0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        U.push_back(i);
        Key.push_back(1);
    }

    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;        
        if(Union(x,y) == true && answer == 0) answer = i+1;
    }

    cout<<answer;
    return 0;
}