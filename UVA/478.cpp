#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>

#define eps 1e-9

using namespace std;

class Point{
    public:
        double x,y;
        Point(){x=0,y=0;}
        Point(double xx,double yy){
            x=xx,y=yy;
        }
        Point operator+(Point a)
        {
            return Point(x+a.x,y+a.y);
        }
        Point operator-(Point a)
        {
            return Point(x-a.x,y-a.y);
        }
        Point mid(Point ab)
        {
            return Point((x+ab.x)/2.0 , (y+ab.y)/2.0 );
        }
        double distance(Point p)
        {
            return (p.x-x)*(p.x-x) +((p.y-y)*(p.y-y));
        }
        void operator*(double th)
        {
            x*=th;
            y*=th;
        }
};

class Triangle{
    public:
    Point a,b,c;
    Triangle(){a=Point();b=Point();c=Point();}
    Triangle(Point a,Point b,Point c)
    {
        this->a=a,this->b=a,this->c=c;
    }
    bool isInside(Point p)
    {
        double abc=arae(this->a,this->b,this->c);
        double pab=arae(p,this->a,this->b);
        double pbc=arae(p,this->b,this->c);
        double pca=arae(p,this->c,this->a);
        if(fabs(pab)<eps || fabs(pbc)<eps||fabs(pca)<eps) return 0;
        return fabs(abc-pab-pbc-pca)<eps;
    }
    double arae(Point aa,Point bb,Point cc)
    {
        return fabs((aa.x*(bb.y-cc.y)) + (bb.x*(cc.y-aa.y)) + (cc.x*(aa.y-bb.y)));
    }
};

class Circle{
    public:
    double r;
    Point c;
    Circle(){r=0,c=Point();}
    Circle(Point c,double r)
    {
        this->r=r,this->c=c;
    }
    bool isInside(Point p)
    {
        double dis=p.distance(c);
        return (r*r-dis)>eps;
    }
};


class Rectangle{
    public:
    Point ul,rd;
    Rectangle(){ul=Point();rd=Point();}
    Rectangle(Point a,Point b)
    {
        ul=a,rd=b;
    }
    bool isInside(Point p)
    {
        return p.x-ul.x>eps && rd.x-p.x>eps && p.y-rd.y>eps && ul.y-p.y>eps;
    }
};

class Solution{
    public:
    Triangle t;
    Circle c;
    Rectangle r;
    char what;
    Solution(){t=Triangle();r=Rectangle();c=Circle();}
    void input(char ccc)
    {
        this->what=ccc;
        if(ccc=='r')
        {
            getRectangle();
        }
        else if(ccc=='c')
        {
            getCircle();
        }
        else if(ccc=='t')
        {
            getTriangle();
        }
    }
    bool checkInside(Point p)
    {
        switch(this->what)
        {
            case 'c':
                return c.isInside(p);
                break;
            case 'r':
                return r.isInside(p);
                break;
            case 't':
                return t.isInside(p);
                break;
        }
    }
    void getRectangle()
    {
        scanf("%lf%lf%lf%lf",&r.ul.x,&r.ul.y,&r.rd.x,&r.rd.y);
    }
    void getTriangle()
    {
        scanf("%lf%lf%lf%lf%lf%lf",&t.a.x,&t.a.y,&t.b.x,&t.b.y,&t.c.x,&t.c.y);
    }
    void getCircle()
    {
        scanf("%lf%lf%lf",&c.c.x,&c.c.y,&c.r);
    }
};

int main()
{
//    freopen("out.txt","wt",stdout);
    Solution sol[100];
    char ch[5];
    int ser=1;
    while(scanf("%s",&ch)==1&&ch[0]!='*')
    {
        sol[ser]=Solution();
        sol[ser].input(ch[0]);
        ser++;
    }

    int pt=0;
    Point p(0,0);
    while(cin>>p.x>>p.y)
    {
        pt++;
        if((fabs(p.x-9999.9)<eps)&&(fabs(p.y-9999.9)<eps)) break;
        bool pr=1;
        for(int k=1;k<ser;k++)
        {
            if(sol[k].checkInside(p))
            {
                pr=0;
                printf("Point %d is contained in figure %d\n",pt,k);
            }
        }
        if(pr) printf("Point %d is not contained in any figure\n",pt);
    }
    return 0;
}
/*
r 8.5 17.0 25.5 -8.5
c 20.2 7.3 5.8
t -1.0 -1.0 10.1 2.2 .4 1.4
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
t 20.3 9.8 10.0 -3.2 17.5 -7.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
t -10.0 -10.0 10.0 25.0 30.0 -10.0
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9
*/
