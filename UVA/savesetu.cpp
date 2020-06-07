#include<stdio.h>
#include<string.h>
int main()
{
    long long i,a,t,sum=0;
    char r[1000];
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",&r);
        if(strcmp(r,"report")!=0)
        {
        scanf("%lld",&a);sum+=a;
        }
        else printf("%lld\n",sum);
    }
    return 0;
}
