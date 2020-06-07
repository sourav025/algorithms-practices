#include<stdio.h>
int main()
{
    int val,i,j,k,l,max,t,Lin[102];
    char str1[100],res[100][100];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        max=0;
        for(j=0;j<10;j++)
        {
                getchar();
            scanf("%s%d",&res[j],&val);
            Lin[j]=val;
            if(max<val)
            max=val;
        }
        printf("Case #%d:\n",i);
        for(k=0;k<10;k++)
        {
            if(Lin[k]==max)
            printf("%s\n",res[k]);
        }

    }
    return 0;
}

