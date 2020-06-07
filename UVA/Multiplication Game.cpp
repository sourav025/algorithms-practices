#include<stdio.h>
int main()
{
    double n;
    int i;
    while(scanf("%lf",&n)==1&&n)
    {
        i=1;
        while(n>1.0)
        {
            if(i%2==1.0)n=n/9;
            else n/=2.0;
            i++;
        }
        if(i%2==0)printf("Stan wins.\n");
        else printf("Ollie wins.\n");

    }
    return 0;
}
