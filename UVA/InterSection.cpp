#include<stdio.h>
#include<math.h>

#define eps 1e-5

using namespace std;

struct Point{
    double x,y;
    Point(double xx=0,double yy=0) {x=xx,y=yy;}
};

struct LS{
    Point P,Q;
    double a,b,c;
    LS(Point x,Point y)
    {
        P=x;Q=y;

        a=Q.x-P.x;
        b=P.y-Q.y;
        c=(P.x*Q.y)-(Q.x*P.y);
    }
    bool isIns(LS B)
    {
        if((fabs((a*B.b)-(B.a*b))<eps) || (fabs((a*B.c) - (B.a*c)))<eps) return false;
        return true;
    }
};

int main()
{
    Point p1,p2,a,c,b,d;


    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&a.x,&a.y,&c.x,&c.y);

        b.x=a.x;
        b.y=c.y;

        d.x=c.x;
        d.y=a.y;

        LS P = LS(p1,p2);
        LS AB=LS(a,b);
        LS BC=LS(b,c);
        LS CD=LS(c,d);
        LS DA=LS(a,d);

        if(P.isIns(AB) || P.isIns(BC) || P.isIns(CD) || P.isIns(DA))
        {
            printf("T\n");
        }
        else printf("F\n");


    }
    return 0;
}
