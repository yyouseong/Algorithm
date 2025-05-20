#include <stdio.h>
int city[100001];
int fuel[100001];
int main()
{
    int i,j,a,big,c,n;
    long long int ans=0;
    scanf("%d",&n);
    for(i=1;i<n;i++) scanf("%d",&city[i]);
    for(i=0;i<n;i++) scanf("%d",&fuel[i]);
    big=fuel[0];
    for(i=1;i<n;i++){
        ans+=(long long int)city[i]*big;
        if(big>fuel[i]) big=fuel[i];
    }
    printf("%lld",ans);
    return 0;
}
