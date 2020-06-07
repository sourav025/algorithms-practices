#include<stdio.h>
long long ara[10000000];
int main()
{
    long long i,j,n,k,l,a,b;
    ara[1]=1;
    for(i=2;i<=1000000;i++)
    {
        n=i;
        long long count=1;
        while(n!=1)
        {
            if(n%2==0)n/=2;
            else n=(3*n)+1;
            count++;
        }
        ara[i]=count;
    }
    while(scanf("%lld%lld",&a,&b)==2)
     {
         k=a;l=b;
        if(a>b)
        {
            long long u=a;
            a=b;
            b=u;
        }
        long long max=0;
        for(i=a;i<=b;i++)
        {
            if(max<ara[i])
            {
             max=ara[i];
            }
        }
        printf("%lld %lld %lld\n",k,l,max);
     }
    return 0;
}
