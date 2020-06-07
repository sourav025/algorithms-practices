#include<stdio.h>
int main()
{
    int i,j,t,k,n,p,q,wg;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%d%d%d",&n,&p,&q);
        if(n&&p&&q){
        k=0;
        int count=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&wg);
            k+=wg;count++;
            if(k>q)
            {
                k-=wg;count--;
            }
        }
        if(count>p) {count=p;}
        printf("Case %d: %d\n",j,count);

        }
    }
    return 0;
}
