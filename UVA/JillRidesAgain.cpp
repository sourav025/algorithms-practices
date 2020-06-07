#include<stdio.h>

long long ar[20015];

int main()
{
    //freopen("in.txt","r",stdin);
    int n,mx,m,fs,ls,exf,exl,tst,cas=1;
    scanf("%d",&tst);
    while(tst--)
    {
        scanf("%d",&n);
        int mx=-1,m=-1,fs,ls,exf=-1,exl=-1;

        for(int i=1;i<n;i++)
            scanf("%lld",&ar[i]);
        ar[n]=0;

        long long sum=0;

        for(int i=1;i<n;i++)
        {
            if(sum+ar[i]<0)
                sum=0,exf=-1;
            else if(sum+ar[i]>=0)
            {
                if(exf==-1) exf=i;
                sum+=ar[i];
            }
            if(sum>mx||(sum==mx&&fs==exf))
            {
                mx=sum;
                fs=exf;
                ls=fs+(i-exf+1);
            }
            //printf("sum %d and (%d to %d)\n",sum,exf,ls);
        }
//        printf("\n*************************************\n");
//        printf("sum %lld and (%d to %d)\n",sum,fs,ls);

        if(fs==-1) printf("Route %d has no nice parts\n",cas++);
        else printf("The nicest part of route %d is between stops %d and %d\n",cas++,fs,ls);
    }
    return 0;
}

