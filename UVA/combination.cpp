#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int i,j,k,l,n;
    unsigned long long r;
    //freopen("conb.txt","r",stdin);
    while(scanf("%d%d",&n,&k)==2&&((n!=0)||(k!=0)))
    {
        l=k;
        r=1;
        if(k>(n/2))
        k=n-k;
        for(i=0;i<k;i++)
        {
            r*=n-i;
            r/=i+1;
        }
        printf("%d things taken %d at a time is %llu exactly.\n",n,l,r);
    }
    return 0;
}

