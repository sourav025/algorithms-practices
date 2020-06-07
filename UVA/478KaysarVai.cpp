#define ll long long
#define vi vector <int>
#define pii pair <int,int>
#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <cassert>


using namespace std;


double INF = 1e100;
double EPS = 1e-9;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  bool scan(){return cin>>x>>y;}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

#define de(x,a) fabs(x-a)<EPS
#define dl(x,a) (a-x)>EPS
#define dg(x,a) dl(a,x)

struct tri
{
    PT a,b,c;
    void scan(){a.scan();b.scan();c.scan();}
    bool isinside(PT p)
    {
        double sum=fabs(cross(b-a,c-a));

        double v=fabs(cross(b-p,c-p));
        if(de(v,0))return 0;
        sum-=v;

        v=fabs(cross(a-p,b-p));
        if(de(v,0))return 0;
        sum-=v;

        v=fabs(cross(c-p,a-p));
        if(de(v,0))return 0;
        sum-=v;


        return de(sum,0);
    }
    int id;
};
struct rec
{
    PT a,b;
    void scan(){a.scan();b.scan();}
    bool isinside(PT p)
    {
        return dg( p.x , min( a.x,b.x ) ) && dg( p.y , min( a.y,b.y ) ) && dl( p.x , max( a.x,b.x ) ) && dl( p.y , max( a.y,b.y ) );
    }
    int id;
};
struct cir
{
    PT c;double r;
    void scan(){c.scan();cin>>r;}
    bool isinside(PT p)
    {
        return dl( dist2(p,c),r*r );
    }
    int id;
};

int main()
{
    char cmd;

    //freopen("in.txt","r",stdin);

    vector<cir>cirs;
    vector<rec>recs;
    vector<tri>tris;

    int id=0;

    while( cin>>cmd )
    {
        if(cmd=='*')break;

        ++id;

        if( cmd=='c' )
        {
            cirs.resize( cirs.size()+1 );
            cirs.back().scan();
            cirs.back().id=id;
        }
        if( cmd=='r' )
        {
            recs.resize( recs.size()+1 );
            recs.back().scan();
            recs.back().id=id;
        }
        if( cmd=='t' )
        {
            tris.resize( tris.size()+1 );
            tris.back().scan();
            tris.back().id=id;
        }
    }


    PT p;

    int k=0;
    while(p.scan())
    {
        if( de(p.x,9999.9) && de(p.y,9999.9) )break;
        vector<int>ans;
        k++;
        for( int i =0;i<cirs.size();i++)if( cirs[i].isinside( p ) )ans.push_back( cirs[i].id );
        for( int i =0;i<recs.size();i++)if( recs[i].isinside( p ) )ans.push_back( recs[i].id );
        for( int i =0;i<tris.size();i++)if( tris[i].isinside( p ) )ans.push_back( tris[i].id );
        sort( ans.begin(),ans.end() );
        if( !ans.size() )printf( "Point %d is not contained in any figure\n",k );
        for( int i=0;i<ans.size();i++ )
        {
            printf("Point %d is contained in figure %d\n",k,ans[i]);
        }
    }


    return 0;
}
