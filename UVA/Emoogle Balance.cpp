#include<stdio.h>

int main()
{
    int n,cas=1;
    while(scanf("%d",&n)==1&&n)
    {
        int c1=0,c2=0,x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==0) c2++;
            else if(1<=x&&x<=99)
                c1++;
        }
        printf("Case %d: %d\n",cas++,c1-c2);
    }
    return 0;
}
