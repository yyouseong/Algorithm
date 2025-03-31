#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    double sum = 0;
    double x, x1, x2;
    double y, y1, y2;
    cin>>n>>x>>y;
    x1=x;
    y1=y;

    while(--n)
    {
        cin>>x2>>y2;
        sum += x1*y2 - x2*y1;
        x1=x2;
        y1=y2;
    }

    sum+=x2*y-x*y2;

    cout<<fixed;
    cout.precision(1);
    
    cout<<abs(sum/2);
    return 0;
}