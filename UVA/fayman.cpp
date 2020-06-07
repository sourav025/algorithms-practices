#include<stdio.h>
int main()
{
    long long i,k,n;
    while(scanf("%lld",&n)==1&&n)
    {
        k=n*(n+1)*((2*n)+1)/6;
        printf("%lld\n",k);
    }
    return 0;
}
