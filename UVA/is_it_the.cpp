#include<stdio.h>
int main()
{
    long long t,i,a,b,c;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("Case %lld: ",i);
        if(a+b>c&&b+c>a&&c+a>b)
        {
            if(a==b&&b==c&&c==a)printf("Equilateral\n");
            else if((a==b&&a!=c)||(b==c&&a!=b)||(c==a&&b!=c))
            printf("Isosceles\n");
            else if((a!=b&&b!=c&&c!=a))printf("Scalene\n");
        }
        else printf("Invalid\n",i);
    }
    return 0;
}
