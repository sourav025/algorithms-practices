#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[10000000],res[10000000];
int main()
{
    long long i,j,k,l,h,n,cas=1;
    while(scanf("%lld%lld",&h,&n)==2&&(h||n))
    {
        for(i=0;i<h;i++)
        scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        scanf("%lld",&res[i]);
        printf("CASE# %lld:\n",cas++);
        sort(a,a+h);
        for(i=0;i<n;i++)
        {
            int flag=0;
            for(j=0;j<h;j++)
            {
                if(res[i]==a[j])
                {
                   flag=1;
                   printf("%lld found at %lld\n",res[i],j+1);
                   break;
                }
            }
            if(flag==0)
            printf("%lld not found\n",res[i]);
        }
    }
    return 0;
}
