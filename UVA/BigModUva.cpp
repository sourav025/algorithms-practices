#include<stdio.h>
#include<math.h>
long long bigmod(long long b,long long p,long long m) {
if (p == 0)
return 1;
else if (p%2 == 0)
return (bigmod(b,p/2,m)*bigmod(b,p/2,m)) % m;
else
return ((b % m) * bigmod(b,p-1,m)) % m;
}
int main()
{
    long long b,p,m,res;
    while(scanf("%lld%lld%lld",&b,&p,&m)==3)
    {
        res=bigmod(b,p,m);
        printf("%lld\n",res);
    }
    return 0;
}
