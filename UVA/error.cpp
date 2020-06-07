#include<stdio.h>
int a[109][109];
int main()
{
    int cas,i,j,k,l,t;

    while(scanf("%d",&t)==1&&t)
    {
        int er=0,ec=0;
         int ero[1000]={0},eco[1000]={0};
        for(i=1;i<=t;i++)
        {
            for(j=1;j<=t;j++)
            {
                scanf("%d",&a[i][j]);
                ero[i]+=a[i][j];
            }
        }
        for(i=1;i<=t;i++)
        {
            for(j=1;j<=t;j++)
            {
                eco[i]+=a[j][i];
            }
        }
        er=0;ec=0;
        for(i=1;i<=t;i++)
        {
            if(ero[i]%2!=0)
            {
                er++;
                k=i;
            }
            if(eco[i]%2!=0)
            {
                ec++;
                l=i;
            }
        }
        if(ec==0&&er==0)
        {
            printf("OK\n");
        }
        else if(ec==1&&er==1)
        printf("Change bit (%d,%d)\n",k,l);
        else printf("Corrupt\n");
    }
    return 0;
}
