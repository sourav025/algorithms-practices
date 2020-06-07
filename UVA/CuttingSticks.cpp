#include<stdio.h>
#include<string.h>

#define inf 999999999
#define min(a,b) ((a<b)?(a):(b))


int dp[55][55],ar[55],n,now[55][55],T=1;

int back(int st,int en)
{
    if(st+1==en) return 0;
    if(now[st][en]==T) {return dp[st][en];}

    now[st][en]=T;

    int ans,mn=inf;
    for(int i=st+1;i<en;i++)
    {
        ans = back(st,i)+back(i,en) + ar[en]-ar[st];
        mn=min(mn,ans);
    }
    return dp[st][en]=mn;
}

int main()
{
    int len;
    while(scanf("%d",&len)==1&&len)
    {
        T++;
        scanf("%d",&n);ar[0]=0; ar[n+1]=len;
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        printf("The minimum cutting is %d.\n",back(0,n+1));
    }
    return 0;
}
