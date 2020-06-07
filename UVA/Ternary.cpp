#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long res[32];
int main()
{
    long long a,b,c,i;
    while(scanf("%lld",&a)==1&&a>=0)
    {
        c=0;
    while(a>2)
    {
        b=a%3;
        a=a/3;
        res[c++]=b;
    }
    res[c]=a;
    for(i=c;i>=0;i--)
    {
        printf("%lld",res[i]);
    }
    printf("\n");
    }
    return 0;
}

