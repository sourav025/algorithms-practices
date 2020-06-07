#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

vector<int> prime;
map<long long,bool> mp;


void pre(){
    bool ar[1000009];
    for(int i=2;i*i<1000009;i++)
        if(!ar[i])
        for(int j=i+i;j<1000009;j+=i)
            ar[j]=1;

    for(int j=2;j<1000009;j++)
        if(!ar[j])
            prime.push_back(j);
    prime.push_back(1000033);
}


int main()
{
    pre();
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        long long n;
        scanf("%lld",&n);

        while(mp[n]);

        if(!mp[n]) mp[n]=1;

        int len=sqrt(n*1.0);
        int res=1;

        for(int i=0;prime[i]<=len;i++)
        {
            if(n%prime[i]==0)
            {
                int cnt=1;
                while(n%prime[i]==0&&n>0)
                    n/=prime[i],cnt++;
                res*=cnt;
                len=sqrt((double)n);
            }
        }
        if(n>1) res=res*2;
        printf("Case %d: %d\n",cas,res-1);

    }
    return 0;
}
