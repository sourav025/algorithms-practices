#include<stdio.h>
#include<math.h>

#define eps 1e-5

double getdown(double a,double b,double c)
{
    if(a<=eps || c<=eps || c<=eps ) return -eps;

    double r= ((1/a)+(1/b)+(1/c)) * ((1/a)+(1/b)-(1/c)) * ((1/b)+(1/c)- (1/a)) * ((1/c)+(1/a)-(1/b));
    //printf("Before res = %.3lf\n",r);
    if( eps+r <= eps ) {
        return -eps;
    }
    return sqrt(r);
}

int main()
{
    double ha,hb,hc,area;
    int n;scanf("%d",&n);
    while(n>0)
    {
        scanf("%lf%lf%lf",&ha,&hb,&hc);
        double rs=getdown(ha,hb,hc);
        //printf("Before res = %.3lf\n",rs);
        if(fabs( eps + rs ) <= eps ){
            printf("These are invalid inputs!\n");
            n--;
        }
        else printf("%.3lf\n",(1.0/rs)+eps);
    }
    return 0;
}
