#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
long long a[6000],res[6000];
int main()
{
    long long i,j,k,l,t,n,cas=1;
    while(scanf("%lld",&t)==1&&t)
    {
        for(i=0;i<t;i++)
        scanf("%lld",&a[i]);
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&res[i]);
        printf("Case %lld:\n",cas++);
        for(i=0;i<n;i++)
        {
            long long min=0,c=0,minF=0;
            for(j=0;j<t;j++)
            {
                for(k=j+1;k<t;k++)
                {
                    long long ans1=abs(a[j]+a[k]-res[i]);
                    //printf("ans1 %d ",ans1);
                    c++;
                    if(c==1){min=a[j]+a[k];minF=ans1;}
                    if(ans1<=minF)
                    {
                        minF=ans1;
                        min=a[j]+a[k];
                    }
                    //printf("minF %d\n",minF);
                }
            }
            printf("Closest sum to %lld is %lld.\n",res[i],min);
        }
    }
    return 0;
}
