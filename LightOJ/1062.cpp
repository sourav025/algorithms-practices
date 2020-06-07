#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>

#define eps 1e-9

using namespace std;

double x,y,c;

double S(double a)
{
    return (a*a);
}

double bs()
{
    double lo=0,hi=min(x,y);

    while(hi-lo>(1e-6))
    {
        double mid=((lo+hi)/2.0);
        if( 1/sqrt(S(x)-S(mid)) + 1/sqrt(S(y)-S(mid)) - 1/c <= 0 )
            lo=mid;
        else hi=mid;
    }
    return (lo+hi)/2.0;
}

int main()
{
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>x>>y>>c;
        printf("Case %d: %.8lf\n",cas,bs()+eps);
    }

    return 0;
}
/*
4
30 40 10
12.619429 8.163332 3
10 10 3
10 10 1
*/
