#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))

int dp[209][209],n,w,k,ar[209],nai[209];

void fill()
{
    for(int i=0;i<n;i++)
    {
        nai[i]=1;
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]-ar[i]<=w)
                nai[i]++;
            else break;
        }
    }
}

int cmp(const int &a,const int &b)
{
    return a<b;
}



int back(int cur,int jharu)
{
    if(cur>=n || jharu<0) return 0;

    if(dp[cur][jharu]!=-1) return dp[cur][jharu];

    dp[cur][jharu]=  max( nai[cur]+back(cur+nai[cur],jharu-1) , back(cur+1,jharu) );

    return dp[cur][jharu];
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(ar,0,sizeof(ar));
        memset(dp,-1,sizeof(dp));
        scanf("%d%d%d",&n,&w,&k);
        for(int i=0;i<n;i++) scanf("%d%d",&ar[i],&ar[i]);
        sort(ar,ar+n,cmp);
        fill();
        int res=back(0,k-1);
        printf("Case %d: %d\n",cas,res);
    }
    return 0;
}


