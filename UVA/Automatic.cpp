#include<stdio.h>
int main()
{
    int i,n,t,ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        ans=(((((n*567)/9)+7492)*235)/47)-498;
        ans=((ans%100)/10);
        if(ans<0)ans*=-1;
        printf("%d\n",ans);
    }
    return 0;
}
