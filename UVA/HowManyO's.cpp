#include<stdio.h>

typedef long long Long;

Long axp[15];


Long zr(Long n)
{
    if(n<0) return 0;
    Long ans=1,pre=0,post=0,id=1;

    while(n>9)
    {
        pre=n/10;
        if(n%10==0) {
                ans+=((pre-1)*axp[id])+post+1;
//            printf("Inz=%lld post=%lld and %lld\n",((pre-1)*axp[id])+post+1,post,(pre-1)*axp[id]);
        }
        else {ans+=pre*axp[id];
//            printf("Notz=%lld\n",pre*axp[id]);
        }

        post=((n%10)*axp[id])+post;
        id++;
        n/=10;
//        printf("pre=%lld post=%lld mod=%lld ans=%lld\n",pre,post,(n%10),ans);
    }
    return ans;
}


int main()
{
    axp[1]=1;
    for(int i=2;i<15;i++)
        axp[i]=axp[i-1]*10LL;
    Long m,n;
    while(scanf("%lld%lld",&m,&n)==2&&m>-1&&n>-1)
    {
//            printf("Res=%lld\n",zr(m));
//            printf("------------------------------------------------\n");
//            printf("Res=%lld\n",zr(n-1));
//

            if(m<n) m=m^n,n=m^n,m=m^n;

            printf("%lld\n",zr(m)-zr(n-1));

    }
    return 0;
}
