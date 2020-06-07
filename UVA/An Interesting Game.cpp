#include<stdio.h>

int sum(int x,int k)
{
    return (x*k)+((k*(k-1))/2);
}

int main()
{
    int n,x,k,t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d",&n,&k,&x);
        printf("Case %d: %d\n",cas,((n*(n+1))/2) - sum(x,k) );
    }
    return 0;
}
