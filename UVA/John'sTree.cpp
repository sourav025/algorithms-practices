#include<stdio.h>
#define mod  1000000007LL

typedef unsigned long long ull;

ull d,v,res;

ull pow(ull x, ull p)
{
    if(p==0) return 1;
    if(p==1) return x;
    if(p%2)
    {
        ull a= pow(x,p-1)%mod;
        return (a*x)%mod;
    }
    ull a=pow(x,p/2)%mod;
    return (a*a)%mod;
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%llu%llu",&d,&v);

        if( v==1LL && d>1LL ) {
            printf("Case %d: -1\n",cas);continue;
        }

        if(d==0LL) res=1LL;
        else if(v==1LL) res=2LL;
        else if(v==2LL)
        {
            res = 1 + (d<<1LL);
            res%=mod;
        }
        else
        {
            res = (pow((v+mod-1LL)%mod, d-1LL) + mod -1LL)%mod;
            res = (res * pow((v+mod-2LL)%mod,mod-2LL) ) %mod;

            ull aa = ((v%mod) * ((v+mod-1LL)%mod)%mod);

            res = ( res * aa )%mod;
            res = (res + v + 1LL)%mod;
        }

        printf("Case %d: %llu\n",cas,res);
    }
}
