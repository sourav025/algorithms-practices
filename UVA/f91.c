#include<stdio.h>
int f91(int x)
{
    if(x<=100)x=f91(f91(x+11));
    else if(x>=101)
    return x-10;
}
int main()
{
    int n,u;
    while(scanf("%d",&n)==1&&n)
    {
        u=f91(n);
        printf("f91(%d) = %d\n",n,u);
    }
    return 0;
}
