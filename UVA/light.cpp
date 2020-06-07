#include<stdio.h>
#include<math.h>
int main()
{
    long long i,j,k,l,n;
    double m;
    while(scanf("%lld",&n)==1&&n)
    {
        m=sqrt((double)n);
        if(m==(long long)m)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
