#include<stdio.h>
#include<string.h>

#define inf (1<<30)
#define min(a,b) ((a<b)?(a):(b))

int cost[21][3],dp[21][3],n;

int back(int cur,int color)
{
    if(cur+1==n) return cost[cur][color];
    if(dp[cur][color]!=-1) return dp[cur][color];
    int ans=inf;
    for(int i=0;i<3;i++)
        if(i!=color)
         ans=min(ans,cost[cur][color]+back(cur+1,i));
    return dp[cur][color]=ans;
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            scanf("%d",&cost[i][j]);
        int res=back(0,0);
        for(int i=1;i<3;i++)
            res=min(res,back(0,i));
        printf("Case %d: %d\n",cas,res);
    }
    return 0;
}
