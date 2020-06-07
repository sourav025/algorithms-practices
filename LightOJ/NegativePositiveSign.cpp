#include<stdio.h>

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case %d: %lld\n",cas,(n/2)*m);
    }
    return 0;
}
