#include<stdio.h>
#include<math.h>

#define pi acos(-1)

double tarea, rarea,Rarea,a,b,c;

void solve()
{
    double s=(a+b+c)/2.0;
    tarea=sqrt(s*(s-a)*(s-b)*(s-c));

    rarea = tarea/s;
    rarea = pi*rarea*rarea;

    Rarea = (((a/4.0)*b*c)/tarea);
    Rarea= (pi*Rarea*Rarea)-tarea;
    tarea-=rarea;
}

int main()
{
    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        solve();
        printf("%.4lf %.4lf %.4lf\n",Rarea,tarea,rarea);
    }
    return 0;
}
