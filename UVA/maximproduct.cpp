#include<stdio.h>
int main()
{
    long long a[100],n,res,i,j,k=1,l,max,p;
    while(scanf("%lld",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
            max=0;
            for(i=0;i<n;i++)
            {
                res=1;
                for(j=i;j<n;j++)
                {
                    res*=a[j];
                    if(res>max)max=res;
                }
            }
           printf("Case #%lld: The maximum product is %lld.\n\n",k,max);
        k++;
    }
    return 0;
}
