#include<stdio.h>
int main()
{
    long long n;
    while(scanf("%lld",&n)==1&&n>=1)
    {
        if(n==1)printf("0%%\n");
        else printf("%lld%%\n",n*25);
    }
    return 0;
}
