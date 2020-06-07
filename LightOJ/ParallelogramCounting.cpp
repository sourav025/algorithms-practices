#include<stdio.h>
#include<math.h>
#include<map>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

#define eps 1e-8

struct point{
    double x,y;
    point(double xx=0,double yy=0)
    {
        x=xx,y=yy;
    }
    void scan()
    {
        cin>>x>>y;
    }
    point getMid(point& b)
    {
        return point((x+b.x)/2.0 , (y+b.y)/2.0);
    }
    void print()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
}ar[1009];

class cmp{
    public:
    bool operator()(const point& a,const point& b)
    {
        return (fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps)||(a.x<b.x || a.y<b.y);
    }
};


int main()
{
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int n;cin>>n;
        for(int i=0;i<n;i++)
            ar[i].scan();
        vector<point> mid;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                mid.push_back(ar[i].getMid(ar[j]));
        sort(mid.begin(),mid.end(),cmp());
        for(int i=0;i<mid.size();i++)
        {
            mid[i].print();
        }
    }
    return 0;
}
