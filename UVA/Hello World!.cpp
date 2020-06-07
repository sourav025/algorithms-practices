#include<stdio.h>
#include<math.h>
int main()
{
    long long i,c=0,k,cas=1,n;
    while(scanf("%lld",&n)==1&&n>0)
    {
        c=0;k=1;
        while(k<n)
        {
            c++;
            k*=2;
        }
        printf("Case %lld: %lld\n",cas,c);
        cas++;
    }
    return 0;
}
