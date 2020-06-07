#include<stdio.h>
#include<math.h>

#define eps 1e-9
#define pi acos(-1)

int main()
{
    int t,cas;scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        double r,d,h2,h1,th;
        scanf("%lf%lf%lf",&r,&d,&h2);

        double ex1=acos((r-d)/r);
        double ex2=acos((r-h2)/r);

        h1=h2+2*sin(ex1-ex2) * sqrt((2*d*r)-d*d);

        printf("Case %d: %.4lf\n",cas,h1);

    }
    return 0;
}

