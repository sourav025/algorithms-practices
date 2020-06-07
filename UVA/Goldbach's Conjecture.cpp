#include<stdio.h>
int a[1000009],res[10000009];
void Prime()
{
    for(int i=2;i<=1000000;i++)
    {
        if(a[i]!=1)
        {
            for(int j=i+i;j<=1000000;j+=i)
            a[j]=1;
        }
    }
}
int main()
{
    Prime();
    int i,j,k,l,n,x,y,max;
    while(scanf("%d",&n)==1&&n)
    {
        l=0;
        k=0;
        for(i=3;i<=n;i+=2)
        {
            if(a[i]!=1&&a[n-i]!=1)
            {
                l=1;
                x=i;
                y=n-i;
                if(y<x)
                {
                    i=x;
                    x=y;
                    y=i;
                }
                break;
            }
        }
        if(l==1)
        {
            printf("%d = %d + %d\n",n,x,y);
        }
        else printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
