#include<stdio.h>
#include<string.h>
char ch[1000],res[200][20];
int check(int n,int m);
int main()
{
    int i,j,k,l,m,r,count;
    while(scanf("%d",&l)==1&&l)
    {
        getchar();
        gets(ch);
        for(i=0;i<strlen(ch);i++)
        {
            k=0;m=0;
            for(j=i+1;j<=l;j++)
            {
                if(ch[j])
                res[m][k]=ch[j];
            }
            m++;
        }
        int max=0;
        for(i=0;i<=m;i++)
        {
            for(j=i+1;j<=m;j++)
            {
                if(strcmp(res[i],res[j])==0)
                {
                    count++;
                }
            }
            if(count>max)
            {
                max=count;
                r=i;
            }
        }
        printf("%s\n",res[r]);
    }
    return 0;
}
