#include<stdio.h>
int main()
{
    long long i,n,a,b,sum;
    while(scanf("%lld",&n)==1&&n)
    {
        a=0,b=1,sum=0;
        for(i=0;i<n;i++)
        {
            sum=a+b;
            a=b;
            b=sum;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
