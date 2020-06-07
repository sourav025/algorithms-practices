#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    long long  ar[6];
    long long n,i,k,a,b,c,d;
    scanf("%lld",&n);
    for(k=1;k<=n;k++)
    {
        for(i=0;i<4;i++)
        scanf("%lld",&ar[i]);
        sort(ar,ar+4);
        if(ar[0]==ar[1]&&ar[1]==ar[2]&&ar[2]==ar[3])
        {
            printf("square\n");
        }
        else if(ar[0]==ar[1]&&ar[2]==ar[3])
        {
            printf("rectangle\n");
        }
        else if(ar[0]+ar[1]+ar[2]>=ar[3])
        printf("quadrangle\n");
        else printf("banana\n");
    }
    return 0;
}
