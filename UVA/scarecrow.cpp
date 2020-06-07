#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,t,n,cas;
    char ch[280];
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        int count=0;
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%c",&ch[i]);
        }
        for(i=0;i<n;i++)
        {
            if(ch[i]=='.'&&ch[i]!='\0')
            {
                count++;i+=2;
            }
        }
        printf("Case %d: %d\n",cas,count);
    }
    return 0;
}
