#include<stdio.h>
int main()
{
    int t,n,i,j,h,l,k,p;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        h=0;l=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&k);
            if(j==0){p=k;}
            else if(k<p){h++;p=k;}
            else if(k>p){l++;p=k;}
        }
        printf("Case %d: %d %d\n",i,l,h);
    }
    return 0;
}
