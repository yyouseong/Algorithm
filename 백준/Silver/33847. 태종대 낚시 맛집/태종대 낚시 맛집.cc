#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct fish{
    int x,s,w;
};

bool cmp_s(fish a,fish b){ return a.s>b.s; }
bool cmp_x(fish a,fish b)
{
    if(a.x == b.x) return a.s>b.s;
    return a.x<b.x;
}


int main()
{
    ios_base::sync_with_stdio(false);

    int n,c, maxN = 0;
    cin>>n>>c;
    vector<fish>Fish(n);
    for(int i=0;i<n;i++)
    {
        int x,s,w;
        cin>>x>>s>>w;
        Fish[i]={x,s,w-c*x};
        maxN += x;
    }

    
    int answer = 0;
    sort(Fish.begin(),Fish.end(),cmp_x);
    
    for(int i=1;i<=maxN;i++)
    {
        int t = i;
        int maxSum = 0;
        int useT = 0;
        vector<fish>Cur = Fish;
        vector<bool>Chk(10001,0);

        while(true)
        {
            vector<fish> Decoy;
            for(int j=0;j<Cur.size();j++)
                if(Cur[j].x<=t && Chk[Cur[j].s] == 0) Decoy.push_back(Cur[j]);
            
            if(Decoy.empty()) break;
            sort(Decoy.begin(),Decoy.end(),cmp_s);

            t -= Decoy.front().x;
            useT += Decoy.front().x;
            maxSum += Decoy.front().w;
            Chk[Decoy.front().s] = 1;

            //Cur.erase(remove_if(Cur.begin(),Cur.end(), [&](const fish &f){return f.s==Decoy.front().s;}),Cur.end());
        }
        if(answer<maxSum) answer = maxSum;
    }

    cout<<answer;
    return 0;
}