#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define eps 1e-10

int main()
{
    double ax,ay,bx,by,cx,cy,dx,dy,th1,th2,h,b,c,d,a;
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&b,&c,&d);
        a= sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));

        th2=acos( (bx-ax) / a); a-=c;
        th1=acos((a*a+d*d-b*b)/(2.0*a*d));
        th1+=th2;
        dx = ax + d*cos(th1) ; dy = ay + d*sin(th1) ;
        cx=dx+(c*cos(th2)); cy=dy+(c*sin(th2));

        printf("Case %d:\n%.10lf %.10lf %.10lf %.10lf\n",cas,cx,cy,dx,dy);
    }
    return 0;
}

