#include<stdio.h>
#define max 1043
#define len 3000

long long fact[max][len];

void calc()
{
    long long i,j,k;
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
    long long i,j,n,k;
    calc();
    while(scanf("%lld",&n)==1)
    {
        printf("%lld!\n",n);
         for(i=len-1;i>0;i--)
            {
                if(fact[n][i]!=0)
                break;
            }
            while(i>=0)
            {
               printf("%lld",fact[n][i]);
               i--;
            }
            printf("\n");

    }
    return 0;
}
