#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int dp[15][15];
int nums[15],n,m;

#define sc(x) int x;scanf("%d",&x)

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&m,&n);
        memset(dp,0,sizeof(dp));
        memset(nums,0,sizeof(nums));

        for(int i=0;i<m;i++) {sc(x);nums[x]=1;dp[1][x]=1;}

        for(int dig=2;dig<=n;dig++)
        {
            for(int i=1;i<=11;i++)
            {
                if(nums[i])
                for(int j=1;j<=11;j++)
                {
                    if(abs(i-j)<=2 && nums[j])
                    {
                        dp[dig][i]+=dp[dig-1][j];
                    }
                }
            }
        }
        int res=0;
        for(int i=1;i<=11;i++)
        {
            res+=dp[n][i];
        }
        printf("Case %d: %d\n",cas,res);
    }
    return 0;
}
