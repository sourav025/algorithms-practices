#include<stdio.h>
#include<math.h>

int dig[10000007];

void pre()
{
    double sx=0;
    for(int i=1;i<10000002;i++)
    {
        sx+=log10(i);
        dig[i] = floor(sx)+1;
    }
}

int main()
{
    pre();
    int t,n;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",dig[n]);
    }
    return 0;
}
