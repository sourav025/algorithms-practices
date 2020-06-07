#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007LL
#define Long long long

map<Long,int> mp;
map<Long,int>::iterator it;

Long bigMod(Long x,Long p);

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        Long n,p,sq;
        scanf("%lld%lld",&n,&p);

        mp.clear();

        for(int i=2;i<=((int)sqrt(n));i++)
        {
            if(n%i==0)
            {
                mp[i]=0;
                while(n%i==0)
                {
                    n/=i;
                    mp[i]++;
                }
            }
        }

        if(n>1) mp[n]++;

        Long sum=1LL;

        for(it=mp.begin();it!=mp.end();it++)
        {
            Long a=(*it).first;
            Long b=(*it).second * p;
            Long aa= (bigMod(a,b+1)+mod-1)%mod;  /// a^0 + a^1 + a^2+ .... + a^n = ((a^(n+1))-1) / (a-1)
            aa=(bigMod(a-1,mod-2)*aa)%mod;
            sum= (sum*aa)%mod;
        }
        printf("Case %d: %lld\n",cas,sum);

    }
    return 0;
}

Long bigMod(Long x,Long p)
{
    if(p==0) return 1LL;
    if(p&1) return (bigMod(x,p-1)*(x%mod))%mod;
    Long xx=bigMod(x,p/2);
    return (xx*xx)%mod;
}

//3
//12 2
//12 1
//36 2
