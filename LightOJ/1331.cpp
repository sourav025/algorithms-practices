#include<stdio.h>
#include<math.h>
#define eps 1e-9
int main()
{
    double r1,r2,r3,a,b,c,th1,th2,th3,s,area;

    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        a=r1+r2;b=r2+r3;c=r3+r1;
        s=((a+b+c)*0.5);

        area=sqrt(s*(s-a)*(s-b)*(s-c));

        th2=acos((b*b+c*c-a*a)/(2.0*b*c));
        th1=acos((c*c+a*a-b*b)/(2.0*a*c));
        th3=acos((a*a+b*b-c*c)/(2.0*a*b));

        area-=(0.5*(th1*r1*r1+th3*r2*r2+th2*r3*r3));

        if(area<0) area*=-1.0;

        printf("Case %d: %.8lf\n",cas,area);

    }
    return 0;
}
/*
3
1.0 1.0 1.0
2 2 2
3 3 3
*/
