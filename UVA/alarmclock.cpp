#include<stdio.h>
int main()
{
    int i,m,h,h1,h2,m1,m2;
    while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2)==4&&(h1||h2||m1||m2))
    {
        if(m1>m2){m2+=60;h1+=1;}
        m=m2-m1;
        if(h1>h2){h2+=24;}
        h=h2-h1;
        m+=(h*60);
        printf("%d\n",m);
    }
    return 0;
}
