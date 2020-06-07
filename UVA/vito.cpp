#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    long long i,n,j,k,l,t,cas,min,sum,a[1000];
    scanf("%lld",&t);
    for(cas=0;cas<t;cas++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            {scanf("%lld",&a[i]);}
            sort(a,a+n);
            min=0;
            for(i=0;i<n;i++)
            {
                sum=0;//printf("*");
                for(j=0;j<n;j++)
                {
                    sum+=labs(a[i]-a[j]);
                    //printf("%lld ",labs(a[i]-a[j]));
                }
                //printf("\n");
                if(i==0)min=sum;
                if(sum<min)min=sum;
            }
            printf("%lld\n",min);
    }
    return 0;
}
