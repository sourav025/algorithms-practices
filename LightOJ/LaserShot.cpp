#include<stdio.h>
#include<algorithm>
#include<utility>
#include<math.h>
#include<vector>
using namespace std;

#define eps 1e-12
#define inf (1<<30)
#define eq(a,b) fabs(a-b)<eps
#define max(a,b) ((a>b)?(a):(b))

typedef pair<double,double> Point;
Point points[709];

double getSlope(Point a,Point b)
{
    if(eq(a.first,b.first)) return inf;
    return ((a.second-b.second)/(a.first-b.first));
}

int main()
{
    int t,n,tot;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        tot=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            points[i]=make_pair(x,y);
        }
        if(n<=2) tot=n;
        else {

            vector<double> slop;

            for(int i=0;i<n;i++)
            {
                slop.clear();
                for(int j=0;j<n;j++)
                    if(i!=j)
                        slop.push_back(getSlope(points[i],points[j]));
                sort(slop.begin(),slop.end());
                int s=1;
                double ex=-inf;
                for(int k=0;k<slop.size();k++)
                {
                    if(eq(ex,slop[k])) {s++;}
                    else {
                        tot=max(tot,s);
                        ex=slop[k];
                        s=2;
                    }
                }
                tot=max(tot,s);
            }

        }
        printf("Case %d: %d\n",cas,tot);
    }
    return 0;
}
