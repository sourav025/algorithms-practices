#include<stdio.h>
#define MAX 5009
#define LEN 8000
int num[MAX][LEN];
void fib()
{
    int i,j,k,l;
    num[0][0]=0;
    num[1][0]=1;
    num[2][0]=1;
    for(i=3;i<MAX;i++)
    {
        for(j=0;j<LEN;j++)
        {
            num[i][j]+=num[i-2][j]+num[i-1][j];
            if(num[i][j]>9)
            {
                num[i][j+1]+=num[i][j]/10;
                num[i][j]%=10;
            }
        }
    }
}
int main()
{
    int i,j,k,l,n;
    fib();
    while(scanf("%d",&n)==1)
    {
        printf("The Fibonacci number for %d is ",n);
        i=LEN-1;
        while(num[n][i]==0&&i>0)
        {
            i--;
        }
        while(i>=0)
        {
            printf("%d",num[n][i]);
            i--;
        }
        printf("\n");
    }
    return 0;
}
