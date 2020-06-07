#include<stdio.h>
#include<string.h>
char ch[500],res[500];
int main()
{
    int i,j,k,l,n;
    while(scanf("%d",&n)==1&&n)
    {
        scanf("%s",ch);
        l=strlen(ch);
        int cnt=0;k=0;
        n=l/n;
        for(i=0;i<l;i++)
        {
            cnt++;
            res[k++]=ch[i];
            if(cnt==n)
            {
                res[k]='\0';
                for(j=k-1;j>=0;j--)
                printf("%c",res[j]);
                k=0;
                cnt=0;
                memset(res,'\0',n+2);
            }
        }
        printf("\n");
        memset(ch,'\0',l+2);
    }
    return 0;
}
