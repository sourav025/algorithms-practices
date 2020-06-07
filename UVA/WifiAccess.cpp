#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define eps 1e-9

#define ls(x,y) (fabs(x-y)<eps || x<y )

class Point{
    double x,y;
public:
    Point(double xx=0,double yy=0)
    {
        this->x=xx;this->y=yy;
    }
public:
    double distance(Point p)
    {
        return ((p.x-x)*(p.x-x)+ (p.y-y)*(p.y-y));
    }
    void getXY(){
        scanf("%lf%lf",&x,&y);
    }
};

class Circle{
    Point c;
    double r;
public:
    Circle(Point p,double rr)
    {
        c=p;r=rr*rr;
    }
public:
    bool isInside(Point p){
        double dis=(p.distance(c));
        return ls(dis,r);
    }

};


int main()
{
    vector<Circle> circle;
    int t,cs,ps;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&cs,&ps);
        printf("Case %d:\n",cas);
        circle.clear();
        for(int i=0;i<cs;i++) {
            double x,y,r;
            cin>>x>>y>>r;
            Point p(x,y);
            circle.push_back(Circle(p,r));
        }

        for(int i=0;i<ps;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            bool f=0;
            for(int c=0;c<cs;c++)
            {
                if(circle[c].isInside(Point(x,y)))
                {
                    f=1;
                    printf("Yes\n");break;
                }
            }
            if(!f) printf("No\n");
        }

    }

    return 0;
}
