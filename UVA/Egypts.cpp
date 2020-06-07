#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3&&(a||b||c))
    {
        a*=a; b*=b; c*=c;
        if((a+b==c)||(b+c==a)||(c+a==b))
        printf("right\n");
        else
        printf("wrong\n");
    }
    return 0;
}
