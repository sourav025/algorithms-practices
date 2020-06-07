#include<stdio.h>
#include<math.h>
int main()
{
    double s,r,i,j,k,area,l,a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        s=(a+b+c)/2;
        r=sqrt((s-a)*(s-b)*(s-c)/s);
        if(s==0) r=0;
        printf("The radius of the round table is: %.3lf\n",r);
    }
    return 0;
}
