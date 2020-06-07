#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int i,t;
    double min,d,u,v,mt,md;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf%lf%lf",&d,&v,&u);
        printf("Case %d: ",i);
        if(u<=v) printf("can't determine\n");
        else
        {
            mt=d/u;
            md=d/sqrt(u*u-v*v);
            if(md==mt)printf("can't determine\n");
            else printf("%.3lf\n",fabs(mt-md));
        }
    }
    return 0;
}
