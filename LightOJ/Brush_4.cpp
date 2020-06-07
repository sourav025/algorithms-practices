#include<stdio.h>
#include<math.h>
#include<set>
#include<utility>
#include<algorithm>
#include<iostream>
using namespace std;

#define eps 1e-8
#define pi acos(-1)

bool isSame(double a,double b)
{
    return (fabs(a-b) <= eps);
}

double getangle(double a,double b)
{
    double ang=atan2(a,b);
    if(fabs(ang)<=eps || fabs(ang-pi)<=eps)
        return 0.0;
    else if( ang+eps<eps )
        return ang+pi;
    else if( ang - pi >= eps)
        return ang-pi;
    else ang;
}

int main()
{
    cout<<getangle(0,7)<<endl;
    cout<<atan2(0,7)+pi;
    int t,n;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        pair<double,double> ar[18];
        for(int i=0;i<n;i++)
        {

        }

    }
    return 0;
}

