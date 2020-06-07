#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>

//计算几何注意 eps
//叉积 cross 是三角形面积的两倍

//向量 (x,y) 逆时针旋转 a 角，x'=x cos a -y sin a , y'=x sin a+y cos a
//确保 不是 0 向量

//直线参数方程 分别为 P+t1v , Q+t2w , u=P-Q , 求交点 , 解得
//t1=cross(w,u)/cross(v,w)
//t2=cross(v,u)/cross(v,w)
//确保有唯一个交点

//求点 P 到直线 AB距离

//一般是弧度不是角度

using namespace std;
map<long long,int> tree;
map<long long,int>::iterator iter;
const double eps=1e-5;
const double PI=acos(-1);
struct Point
{
    double x,y;
    Point(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    Point()
    {
        x=0;
        y=0;
    }
};
typedef Point Vector;
Vector operator+(Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(Vector A,double p)
{
    return Vector(A.x/p,A.y/p);
}
Vector operator*(double p,Vector A)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(double p,Vector A)
{
    return Vector(A.x/p,A.y/p);
}
bool operator<(const Point& a,const Point& b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int dcmp(double x)
{
    if(fabs(x)<eps)
    {
        return 0;
    }
    else
    return x<0?-1:1;
}
bool operator==(const Point& a,const Point& b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Dot(Vector a,Vector b)
{
    //计算点积
    return a.x*b.x+a.y*b.y;
}
double Cross(Vector a,Vector b)
{
    //计算叉积
    return a.x*b.y-a.y*b.x;
}
double Length(Vector a)
{
    //计算长度
    return sqrt(Dot(a,a));
}
double Angle(Vector A,Vector B)
{
    //计算AB夹角
    return acos(Dot(A,B)/Length(A)/Length(B));
}
double Area2(Point A,Point B,Point C)
{
    //计算三角形ABC的面积的二倍
    return Cross(B-A,C-A);
}
Vector Rotate(Vector a,double rad)
{
    //向量逆时针旋转rad角
    //rad弧度
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Vector Normal(Vector a)
{
    //计算向量的单位法线，即左转90度，长度归一化。
    //用前确保A不是零向量
    double l=Length(a);
    return Vector(-a.y/l,a.x/l);
}
Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    //求解直线P+t*v  Q+t*w 的交点
    //用前确保两条直线有唯一交点
    //当且仅当cross(v,w)!=0
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}
double DistanceToLine(Point p,Point a,Point b)
{
    //计算点P到直线AB距离
    Point v1=b-a;
    Point v2=p-a;
    return fabs(Cross(v1,v2))/Length(v1);
    //如果不取绝对值，得的是有向距离
}
double DistanceToSegment(Point p,Point a,Point b)
{
    //计算点P到线段AB距离
    if(a==b)
    {
        return Length(p-a);
    }
    Vector v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0)
    {
        return Length(v2);
    }
    else
    if(dcmp(Dot(v1,v3))>0)
    {
        return Length(v3);
    }
    else
    {
        return fabs(Cross(v1,v2))/Length(v1);
    }
}
Point GetLineProjection(Point p,Point a,Point b)
{
    //求点在直线上投影
    //AB直线:A+tv , 投影Q的参数为 t0
    //由 Dot(v,P-(A+t0*v))==0 得出
    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
    //线段相交判定
    double c1=Cross(a2-a1,b1-a1);
    double c2=Cross(a2-a1,b2-a1);
    double c3=Cross(b2-b1,a1-b1);
    double c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(Point p,Point a1,Point a2)
{
    //判断一个点在线段上
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}
double ConvexPolygonArea(Point* p,int n)
{
    //从第一个顶点出发把凸多边形分成 n-2 个三角形
    double area=0;
    for(int i=1;i<n-1;i++)
    {
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2;
}
//-------------------------------------------------
struct Circle
{
    Point c;
    double r;
    Circle()
    {

    }
    Circle(Point cc,double rr)
    {
        c=cc;
        r=rr;
    }
    Point point(double a)
    {
        //通过圆心角来求坐标
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
struct Line
{
    //有向直线,左边就是对应的半平面
    Vector v;
    Point p;
    double ang;
    Line(){}
    Line(Point pp,Vector vv)
    {
        p=pp;
        v=vv;
        ang=atan2(v.y,v.x);
    }
    Point point(double a)
    {
        return v+a*(p-v);
    }
    bool operator<(const Line& L) const
    {
        return ang<L.ang;
    }
};
bool OnLeft(Line l,Point pp)
{
    //点Ｐ在有向直线的左边，线上不算
    return Cross(l.v,pp-l.p)>0;
}
Point GetLineIntersection(Line a,Line b)
{
    //二直线相交，假设交点唯一存在
    Vector u=a.p-b.p;
    double t=Cross(b.v,u)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
int getLineCircleIntersection(Line l,Circle cc,double& t1,double& t2,vector<Point>& sol)
{

    double a=l.v.x;
    double b=l.p.x-cc.c.x;
    double c=l.v.y;
    double d=l.p.y-cc.c.y;
    double e=a*a+c*c;
    double f=2*(a*b+c*d);
    double g=b*b+d*d-cc.r*cc.r;
    double delta=f*f-4*e*g;//判别式
    if(dcmp(delta)<0)
    {
        return 0;//相离
    }
    if(dcmp(delta)==0)
    {
        t1=t2=-f/(2*e);
        sol.push_back(l.point(t1));
        return 1;//相切
    }
    t1=(-f-sqrt(delta))/(2*e);
    sol.push_back(l.point(t1));
    t2=(-f+sqrt(delta))/(2*e);
    sol.push_back(l.point(t2));
    return 2;//相交
}
double angle(Vector v)
{
    return atan2(v.y,v.x);
}
int getCircleCircleIntersection(Circle c1,Circle c2,vector<Point>& sol)
{
    double d=Length(c1.c-c2.c);
    if(dcmp(d)==0)
    {
        if(dcmp(c1.r-c2.r)==0)
        return -1;//两圆重合
        return 0;
    }
    if(dcmp(c1.r+c2.r-d)<0)
    return 0;
    if(dcmp(fabs(c1.r-c2.r)-d)>0)
    return 0;

    double a=angle(c2.c-c1.c);//向量C1C2的极角
    double da=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    //计算C1C2到C1P1的角
    Point p1=c1.point(a-da);
    Point p2=c1.point(a+da);
    sol.push_back(p1);
    if(p1==p2)
    return 1;
    sol.push_back(p2);
    return 2;
}
int getTangents(Point p,Circle c,Vector* v)
{
    Vector u=c.c-p;
    double dist=Length(u);
    if(dist<c.r)
    return 0;
    else
    if(dcmp(dist-c.r)==0)
    {
        v[0]=Rotate(u,PI/2);
        return 1;
    }
    else
    {
        double ang=asin(c.r/dist);
        v[0]=Rotate(u,-ang);
        v[1]=Rotate(u,ang);
        return 2;
    }
}
int getTangents(Circle a,Circle b,Point* aa,Point* bb)
{
    int cnt=0;
    if(a.r<b.r)
    {
        swap(a,b);
        swap(aa,bb);
    }
    int d2=(a.c.x-b.c.x)*(a.c.x-b.c.x)+(a.c.y-b.c.y)*(a.c.y-b.c.y);
    int rdiff=a.r-b.r;
    int rsum=a.r+b.r;
    if(d2<rdiff*rdiff)
    {
        return 0;//内含
    }
    double base=atan2(b.c.y-a.c.y,b.c.x-a.c.x);
    if(d2==0&&a.r==b.r)
    return -1;//无穷多条切线
    if(d2==rdiff*rdiff)
    {
        aa[cnt]=a.point(base);
        bb[cnt]=b.point(base);
        cnt++;
        return 1;//内切，1条
    }
    double ang=acos((a.r-b.r)/sqrt(d2));
    aa[cnt]=a.point(base+ang);
    bb[cnt]=b.point(base+ang);
    cnt++;
    aa[cnt]=a.point(base-ang);
    bb[cnt]=b.point(base-ang);
    cnt++;

    if(d2==rsum*rsum)
    {
        aa[cnt]=a.point(base);
        bb[cnt]=b.point(base+PI);
        cnt++;//一条内公切线
    }
    else
    if(d2>rsum*rsum)
    {
        double ang=acos((a.r+b.r)/sqrt(d2));
        aa[cnt]=a.point(base+ang);
        bb[cnt]=b.point(PI+base+ang);
        cnt++;
        aa[cnt]=a.point(base-ang);
        bb[cnt]=b.point(PI+base-ang);
        cnt++;//两条内公切线
    }
    return cnt;
}
Circle CircumscribedCircle(Point p1,Point p2,Point p3)
{
    //三角形外接圆
    double bx=p2.x-p1.x;
    double by=p2.y-p1.y;
    double cx=p3.x-p1.x;
    double cy=p3.y-p1.y;
    double d=2*(bx*cy-cx*by);
    double ccx=(cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+p1.x;
    double ccy=(bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+p1.y;
    Point p=Point(ccx,ccy);
    return Circle(p,Length(p1-p));
}
Circle InscribedCircle(Point p1,Point p2,Point p3)
{
    //三角形内切圆
    double a=Length(p2-p3);
    double b=Length(p3-p1);
    double c=Length(p1-p2);
    Point p=(p1*a+p1*b+p3*c)/(a+b+c);
    return Circle(p,DistanceToLine(p,p1,p2));
}
double torad(double deg)
{
    return deg/180*PI;
}
void get_coord(double r,double lat,double lng,double& x,double& y,double& z)
{
    //经纬度(角度)转化为空间坐标
    lat=torad(lat);
    lng=torad(lng);
    x=r*cos(lat)*cos(lng);
    y=r*cos(lat)*sin(lng);
    z=r*sin(lat);
}
struct Polygon
{
    int n;
    Point p[1000];
    Polygon()
    {
        n=0;
    }
    Polygon(int nn,Point* pp)
    {
        n=nn;
        for(int q=0;q<n;q++)
        {
            p[q]=pp[q];
        }
    }
    Point operator[](int a) const
    {
        return p[a];
    }
};
int isPointInPolygon(Point p,Polygon po)
{
    int wn=0;
    int n=po.n;
    for(int i=0;i<n;i++)
    {
        if(OnSegment(p,po[i],po[(i+1)%n]))
        return -1;//在边界上
        int k=dcmp(Cross(po[(i+1)%n]-po[i],p-po[i]));
        int d1=dcmp(po[i].y-p.y);
        int d2=dcmp(po[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0)
        wn++;
        if(k<0&&d2<=0&&d1>0)
        wn--;
    }
    if(wn!=0)
    return 1;//内部
    return 0;//外部
}
int ConvexHull(Point* p,int n,Point* ch)
{
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
        m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)
        m--;
        ch[m++]=p[i];
    }
    if(n>1)
    m--;
    return m;
}
double diameter(Point* o,int n,Point *p)
{
    int num=ConvexHull(o,n,p);
    int mi=0;
    int ma=0;
    for(int q=0;q<num;q++)
    {
        if(p[q]<p[mi])
            mi=q;
        if(p[ma]<p[q])
            ma=q;
    }
    int v=ma;
    double ans=(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y);
    ans=max(ans,(p[num-1].x-p[ma].x)*(p[num-1].x-p[ma].x)+(p[num-1].y-p[ma].y)*(p[num-1].y-p[ma].y));
    ans=max(ans,(p[mi].x-p[ma-1].x)*(p[mi].x-p[ma-1].x)+(p[mi].y-p[ma-1].y)*(p[mi].y-p[ma-1].y));
    ans=max(ans,(p[num-1].x-p[ma-1].x)*(p[num-1].x-p[ma-1].x)+(p[num-1].y-p[ma-1].y)*(p[num-1].y-p[ma-1].y));
    for(;mi<v;mi++)
    {
        for(;;)
        {
            int a=dcmp(Cross(p[mi+1]-p[mi],p[ma+1]-p[ma]));
            if(a==0)
            {
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                ma++;
                break;
            }
            if(a>0)
            {
                ans=max(ans,(p[mi].x-p[ma].x)*(p[mi].x-p[ma].x)+(p[mi].y-p[ma].y)*(p[mi].y-p[ma].y));
                ans=max(ans,(p[mi].x-p[ma+1].x)*(p[mi].x-p[ma+1].x)+(p[mi].y-p[ma+1].y)*(p[mi].y-p[ma+1].y));
                ma++;
            }
            if(a<0)
            {
                ans=max(ans,(p[mi+1].x-p[ma].x)*(p[mi+1].x-p[ma].x)+(p[mi+1].y-p[ma].y)*(p[mi+1].y-p[ma].y));
                ans=max(ans,(p[mi+1].x-p[ma+1].x)*(p[mi+1].x-p[ma+1].x)+(p[mi+1].y-p[ma+1].y)*(p[mi+1].y-p[ma+1].y));
                break;
            }
        }
    }
    return ans;
}
int HalfplaneIntersection(Line* l,int n,Point* poly)
{
    sort(l,l+n);
    int first,last;
    Point *p=new Point[n];
    Line *q=new Line[n];
    q[first=last=0]=l[0];
    for(int i=1;i<n;i++)
    {
        while(first<last&&!OnLeft(l[i],p[last-1]))
            last--;
        while(first<last&&!OnLeft(l[i],p[first]))
            first++;
        q[++last]=l[i];
        if(fabs(Cross(q[last].v,q[last-1].v))<eps)
        {
            last--;
            if(OnLeft(q[last],l[i].p))
                q[last]=l[i];
        }
        if(first<last)
            p[last-1]=GetLineIntersection(q[last-1],q[last]);
    }
    while(first<last&&!OnLeft(q[first],p[last-1]))
        last--;
    if(last-first<=1)
        return 0;
    p[last]=GetLineIntersection(q[last],q[first]);
    int m=0;
    for(int i=first;i<=last;i++)
        poly[m++]=p[i];
    return m;
}
void FindBorder(Point* p,int n)
{
    //寻找多边形边界
    int num;
    Point ans[10005];
    Point z[205];
    double x[205];
    int a;
    int min1=0;
    for(int q=0;q<n;q++)
        if(p[q]<p[min1])
            min1=q;
    p[n]=p[0];
    ans[0]=p[min1];
    double s=-PI;
    num=1;
    for(int idx=0;;idx++)
    {
        a=0;
        for(int q=0;q<n;q++)
            if(p[q]==ans[num-1])
            {
                z[a]=p[(q+1)%n];
                x[a]=atan2(-p[q].y+z[a].y,-p[q].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
                z[a]=p[(q+n-1)%n];
                x[a]=atan2(-p[q].y+z[a].y,-p[q].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
            }
        for(int q=0;q<n;q++)
            if(OnSegment(ans[num-1],p[q],p[q+1]))
            {
                z[a]=p[(q+1)];
                x[a]=atan2(-ans[num-1].y+z[a].y,-ans[num-1].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
                z[a]=p[q];
                x[a]=atan2(-ans[num-1].y+z[a].y,-ans[num-1].x+z[a].x)-s-2*PI;
                for(;dcmp(x[a])<=0;)
                    x[a]+=2*PI;
                a++;
            }
        int mi=0;
        for(int q=0;q<a;q++)
            if(x[q]<x[mi])
                mi=q;
        double ma=101000000;
        Point f=z[mi],g;
        for(int q=0;q<n;q++)
            if(SegmentProperIntersection(z[mi],ans[num-1],p[q],p[q+1]))
            {
                g=GetLineIntersection(z[mi],z[mi]-ans[num-1],p[q],p[q]-p[q+1]);
                if(Length(g-ans[num-1])<ma)
                {
                    ma=Length(g-ans[num-1]);
                    f=g;
                }
            }
        ans[num]=f;
        s=atan2(ans[num-1].y-ans[num].y,ans[num-1].x-ans[num].x);
        num++;
        if(ans[num-1]==ans[0])
            break;
    }
    printf("%d\n",num-1);
    for(int q=0;q<num-1;q++)
        printf("%.4lf %.4lf\n",ans[q].x,ans[q].y);
}
Polygon cutPolygon(Polygon& po,Point a,Point s)
{
    Point x,c;
    Polygon ans;
    int sum=0;
    for(int q=0;q<po.n;q++)
    {
        x=po[q];
        c=po[(q+1)%po.n];
        if(OnLeft(Line(a,s-a),x)||OnSegment(x,a,s))
        {
            ans.p[sum]=x;
            sum++;
        }
        if(SegmentProperIntersection(x,c,a,s))
        {
            ans.p[sum]=GetLineIntersection(x,c-x,a,s-a);
            sum++;
        }
    }
    ans.n=sum;
    return ans;
}
//--------------For 3d Vectors----------
//三维计算几何
struct Point3
{
    double x,y,z;
    Point3()
    {
        x=0;
        y=0;
        z=0;
    }
    Point3(double xx,double yy,double zz)
    {
        x=xx;
        y=xx;
        z=zz;
    }
    bool operator==(Point3 p) const
    {
        return dcmp(x-p.x)==0&&dcmp(y-p.y)==0&&dcmp(z-p.z)==0;
    }
};
typedef Point3 Vector3;
Vector3 operator+(Vector3 a,Vector3 b)
{
    return Vector3(a.x+b.x,a.y+b.y,a.z+b.z);
}
Vector3 operator-(Vector3 a,Vector3 b)
{
    return Vector3(a.x-b.x,a.y-b.y,a.z-b.z);
}
Vector3 operator*(Vector3 a,double p)
{
    return Vector3(a.x*p,a.y*p,a.z*p);
}
Vector3 operator/(Vector3 a,double p)
{
    return Vector3(a.x/p,a.y/p,a.z/p);
}
double Dot(Vector3 a,Vector3 b)
{
    return a.x*b.x+a.y*b.y+a.z*b.y;
}
double Length(Vector3 a)
{
    return sqrt(Dot(a,a));
}
double Angle(Vector3 a,Vector3 b)
{
    return acos(Dot(a,b)/Length(a)/Length(b));
}
//平面用点法式表示(p0,n),p0是平面上一个点，n 是平面法向量
double DistanceToPlane(Point3 &p,Point3 &p0,Vector3 &n)
{
    //点p到平面 p0-n 的的距离，n 是单位向量
    return fabs(Dot(p-p0,n));
    //如果不取绝对值，得到的是有向距离
}
Point3 GetPlaneProjection(Point3 &p,Point3 &p0,Vector3 &n)
{
    //点 p 在平面 p0-n 上的投影，n 是单位向量
    return p-n*Dot(p-p0,n);
}
Point3 LinePlaneIntersection(Point3 p1,Point3 p2,Point3 p0,Vector3 n)
{
    //直线 p1-p2 到平面 p0-n 的交点
    //分母为 0 对应直线和平面平行，直线在平面上
    Vector3 v=p2-p1;
    double t=(Dot(n,p0-p1)/Dot(n,p2-p1));//判断分母是否为 0
    return p1+v*t;//如果是线段，判断 t 是不是在 0 和 1 之间
}
Vector3 Cross(Vector3 a,Vector3 b)
{
    return Vector3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double Area2(Point3 a,Point3 b,Point3 c)
{
    return Length(Cross(b-a,c-a));
}
bool PointInTri(Point3 p,Point3 p0,Point3 p1,Point3 p2)
{
    //判断点在三角形内，先判断是否在三角形所在的平面，再用面积关系
    double area1=Area2(p,p0,p1);
    double area2=Area2(p,p2,p1);
    double area3=Area2(p,p0,p2);
    return dcmp(area1+area2+area3-Area2(p0,p1,p2))==0;
}
bool TriSegIntersection(Point3 p0,Point3 p1,Point3 p2,Point3 a,Point3 b,Point3 &p)
{
    //判断线段和三角形是否相交
    //没有考虑线段在平面上的情况
    Vector3 n=Cross(p1-p0,p2-p0);
    if(dcmp(Dot(n,b-a))==0)
        return false;
    else
    {
        double t=Dot(n,p0-a)/Dot(n,b-a);
        if(dcmp(t)<0||dcmp(t-1)>0)
            return false;
        p=a+(b-a)*t;//计算交点
        return PointInTri(p,p0,p1,p2);//判断交点在三角形内
    }
}
double DistanceToLine(Point3 p,Point3 a,Point3 b)
{
    //点 p 到直线 ab 距离
    Vector3 v1=b-a,v2=p-a;
    return Length(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(Point3 p,Point3 a,Point3 b)
{
    //点 p 到线段 ab 距离
    if(a==b)
        return Length(p-a);
    Vector3 v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2))<0)
        return Length(v2);
    else
    if(dcmp(Dot(v1,v3))>0)
        return Length(v3);
    else
        return Length(Cross(v1,v2))/Length(v1);
}
double Volume6(Point3 a,Point3 b,Point3 c,Point3 d)
{
    return Dot(d-a,Cross(b-a,c-a));
}
int main()
{

    int T;
    Point z[5],v,x[5];
    scanf("%d",&T);
    // printf("%d",Length(Point(0,0),Point(3,4)));
    for(int idx=0;idx<T;idx++)
    {
        printf("Case %d: ",idx+1);
        for(int q=0;q<4;q++)
            scanf("%lf%lf",&x[q].x,&x[q].y);
        // sort(z,z+4);
        // v=z[2];
       if(ConvexHull(x,4,z)<4)
       {
            printf("Ordinary Quadrilateral\n");
            continue;
}
             // for(int q=0;q<4;q++)
         // printf("%lf %lf\n",z[q].x,z[q].y);
        if(dcmp(Cross(z[0]-z[3],z[1]-z[2]))==0&&dcmp(Cross(z[0]-z[1],z[3]-z[2]))==0)
        {
         // printf("*\n");
         if(dcmp(Length(z[0]-z[1])-Length(z[1]-z[2]))==0)
         {
             if(dcmp(Dot(z[1]-z[0],z[1]-z[2]))==0)
                 printf("Square\n");
             else
                 printf("Rhombus\n");
         }
         else
         {
             if(dcmp(Dot(z[1]-z[0],z[1]-z[2]))==0)
                 printf("Rectangle\n");
             else
                 printf("Parallelogram\n");
         }
        }
        else
        {
         // printf("*\n");
         if(dcmp(Cross(z[0]-z[3],z[1]-z[2]))==0||dcmp(Cross(z[0]-z[1],z[3]-z[2]))==0)
             printf("Trapezium\n");
         else
             printf("Ordinary Quadrilateral\n");
        }
    }


    return 0;
}
