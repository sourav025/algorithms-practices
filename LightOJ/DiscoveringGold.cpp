#include<stdio.h>

#define min(a,b) ((a<b)?(a):(b))

int True=1,vis[109],n,ar[109];
double dp[115];

double back(int cur)
{
    if(cur>n) return 0.0;
    if(vis[cur]==True) return dp[cur];
    vis[cur]=True;
    dp[cur] = ar[cur];
    if(n==cur) return dp[cur];
    double p=(1.0/(min(6,n-cur)*1.0));
    for(int i=cur+1;i<=min(n,cur+6);i++)
        dp[cur]+=p*back( i );
    return dp[cur];
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++,True++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
        printf("Case %d: %.10lf\n",cas,back(1));
    }
    return 0;
}
