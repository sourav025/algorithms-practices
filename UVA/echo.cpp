#include<stdio.h>
int main()
{
    int i,j,s,p,n,q,a,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int res=0;
        scanf("%d",&n);
        for(j=0;j<n;j++){
        scanf("%d%d%d",&p,&a,&q);
            s=p*q;
            res+=s;
        }
        printf("%d\n",res);
    }
    return 0;
}
