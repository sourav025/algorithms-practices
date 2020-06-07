#include<stdio.h>
#define max 1001
#define len 2600
long long fact[max][len];
void fact1()
{
    long long i,j,k,l;
    fact[0][0]=1;fact[1][0]=1;
    for(i=2;i<max;i++)
    {
        for(j=0;j<len;j++)
        {
            fact[i][j]+=fact[i-1][j]*i;
            if(fact[i][j]>9)
            {
                fact[i][j+1]+=fact[i][j]/10;
                fact[i][j]%=10;
            }
        }
    }
}

int main()
{
    fact1();
    long long i,n,sum;
    while(scanf("%lld",&n)==1)
    {
        sum=0;
        for(i=len-1;i>0;i--)
        if(fact[n][i]!=0)break;
        while(i>=0)
        {
            printf("%lld",fact[n][i]);
            i--;
        }
        printf("\n");
    }
    return 0;
}
