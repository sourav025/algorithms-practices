#include<stdio.h>
double average(double a,double b,double c)
{
    double min=a;
    if(min>b)min=b;
    if(min>c)min=c;
    double sum=a+b+c-min;
    return (sum/2);
}
int main()
{
    double t1,t2,f,a,ct1,ct2,ct3,t,result;
    scanf("%lf",&t);
    for(double i=0;i<t;i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf",&t1,&t2,&f,&a,&ct1,&ct2,&ct3);
        result=t1+t2+f+a+average(ct1,ct2,ct3);
        printf("Case %.0lf: ",i+1);
        if(result>=90)
        printf("A\n");
        if(result>=80&&result<90)
        printf("B\n");
        if(result>=70&&result<80)
        printf("C\n");
        if(result>=60&&result<70)
        printf("D\n");
        if(result<60)
        printf("F\n");
    }
    return 0;
}
