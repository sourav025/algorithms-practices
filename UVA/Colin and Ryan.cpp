#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[10000000];
int main()
{
    long long i,j,q,k,l,c,r,t,cas;
    scanf("%lld",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%lld%lld",&c,&r);
        printf("Case #%lld:",cas);
        if(c==r)
        {
            printf(" 0");
        }
        else
        {
            q=c-r;k=0;
            for(i=1;i*i<=c;i++)
            {
                if(q%i==0)
                {
                    a[k++]=i;
                    if((q/i)!=i)
                    a[k++]=q/i;
                }
            }
            if(k==0&&q>r)a[k++]=q;
            sort(a,a+k);
            for(i=0;i<k;i++){
                if(a[i]>r)
            printf(" %lld",a[i]);}
        }
        printf("\n");
    }
    return 0;
}
