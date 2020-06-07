#include<stdio.h>
#include<math.h>

#define eps 1e-9

double MAX(double a,double b)
{
    return ((a>b)||fabs(a-b)<eps)?a:b;
}

double l,w,h;

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lf%lf",&l,&w);

        if(fabs(l-w)<eps||l>w)
        {
            double tmp=l;l=w;w=tmp;
        }
        double vol,maxVol=-1;

        for(double mid=0.01;mid<=l;mid+=0.01){
            vol=(l-(2*mid))*(w-(2*mid))*(mid);
            maxVol=MAX(maxVol,vol);
        }
        printf("Case %d: %lf",cas,maxVol);
    }
}
