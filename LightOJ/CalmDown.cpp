#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

#define PI acos(-1)
#define eps 1e-8


int main()
{
    int t,cas=1;
    cin>>t;
    while(cas<=t)
    {
        double R,n,r;
        cin>>R>>n;
        double sn=sin(PI/n);
        r=(R*sn)/(1+sn);
        printf("Case %d: %.10lf\n",cas++,r+eps);
    }
    return 0;
}
