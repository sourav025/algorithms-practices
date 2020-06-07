#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
#define EPS 1e-9
#define Z(x) fabs(x)<EPS
#define ge(x,y) (Z(x-y) || x>y)
#define le(x,y) (Z(x-y) || x<y)

class Vector
{
public:
    double x, y;
    Vector(){}
    Vector(double x, double y):x(x),y(y){}
    void scan(){scanf("%lf%lf",&x,&y);}
    Vector operator+(Vector pt)
    {
        return Vector(x+pt.x,y+pt.y);
    }
    Vector operator-(Vector pt)
    {
        return Vector(x-pt.x,y-pt.y);
    }
    Vector operator*(double mul)
    {
        return Vector(x*mul,y*mul);
    }
};

class LineSegment
{
    public:
        Vector v0,v1;
        LineSegment(){}
        LineSegment(Vector begin,Vector end){v0=begin;v1=end;}
        enum IntersectResult { PARALLEL, COINCIDENT, INTERESECTING };
        IntersectResult intersect(const LineSegment& L, double& t0,double &t1)
        {
            double denom = ((L.v1.y - L.v0.y)*(v1.x - v0.x)) -
                          ((L.v1.x - L.v0.x)*(v1.y - v0.y));

            double nume_a = ((L.v1.x - L.v0.x)*(v0.y - L.v0.y)) -
                           ((L.v1.y - L.v0.y)*(v0.x - L.v0.x));

            double nume_b = ((v1.x - v0.x)*(v0.y - L.v0.y)) -
                           ((v1.y - v0.y)*(v0.x - L.v0.x));

            if(Z(denom))
            {
                if(Z(nume_a) && Z(nume_b))
                {
                    return COINCIDENT;
                }
                return PARALLEL;
            }

            t0 = nume_a / denom;
            t1 = nume_b / denom;



            return INTERESECTING;
        }
};

int main()
{
    int T,i;
    scanf("%d",&T);
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    LineSegment l1,l2;

    while(T--)
    {
        l1.v0.scan(); l1.v1.scan();
        l2.v0.scan(); l2.v1.scan();
        double t1,t2;

        int res=l1.intersect(l2,t1,t2);

        switch(res)
        {
            case 0:
                cout<<"NONE"<<endl;
                break;
            case 1:
                cout<<"LINE"<<endl;
                break;
            case 2:
                Vector pt=l1.v0+((l1.v1-l1.v0)*t1);cout<<"POINT ";
                printf("%.2lf %.2lf\n",pt.x+EPS,pt.y+EPS);
                break;
        }

    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;

}
