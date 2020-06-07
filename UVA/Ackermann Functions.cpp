#include<stdio.h>
int main()
{
    long long n,i,j,k,u,l,cnt,max;
    while(scanf("%lld%lld",&l,&u)==2&&u&&l){
    if(u<l)
    {
        k=u;
        u=l;
        l=k;
    }
    max=0;
    for(i=l;i<=u;i++)
    {
        cnt=1;
        n=i;
        if(n%2==0)n/=2;
        else n=3*n+1;
        while(1)
        {
            if(n==1)break;
            if(n%2==0)n/=2;
            else n=3*n+1;
            cnt++;
        }
        if(cnt>max){max=cnt;k=i;}
    }
    printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,u,k,max);}
    return 0;
}
