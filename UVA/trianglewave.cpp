#include<stdio.h>
int main()
{
    //freopen("Sam.txt","r",stdin);
    int t,i,j,k,len,tm,l;
    scanf("%d",&t);
        //printf("\n");
    for(int cas=0;cas<t;cas++)
    {
        scanf("%d%d",&len,&tm);
        for(k=0;k<tm;k++)
        {
            for(i=1;i<=len;i++)
            {
                for(j=1;j<=i;j++)
                {
                    printf("%d",i);
                }
                printf("\n");
            }
            for(i=len-1;i>0;i--)
            {
                for(j=1;j<=i;j++)
                {
                    printf("%d",i);
                }
                printf("\n");
            }
            if(k!=tm-1)
            printf("\n");
        }
        if(cas!=t-1)
        printf("\n");
    }
    return 0;
}
