#include<stdio.h>
#include<math.h>

#define pi acos(-1)
#define tw 1.4142135623730950488016887242097


int main()
{
    double x;
    while(scanf("%lf",&x)==1)
    {
        x=x* sin(72.0*pi/180.0) / sin(63.0*pi/180.0);
        printf("%.10lf\n",x);
    }
    return 0;
}
