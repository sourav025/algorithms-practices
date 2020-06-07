#include<stdio.h>
int main()
{
    long long a,b,c,m,n;
    while(scanf("%lld%lld",&a,&b)==2&&(a||b))
    {
        long long count=0,ex=0;
        while(a!=0||b!=0)
        {
            m=a%10;
            n=b%10;
            c=m+n+ex;
            ex=0;
            if(c>9)
            {
                count++;ex=c/10;
            }
            a=a/10;b=b/10;
        }
        if(count==0)
        printf("No carry operation.\n");
        else if(count==1)
        printf("%lld carry operation.\n",count);
        else
        printf("%lld carry operations.\n",count);
    }
    return 0;
}
