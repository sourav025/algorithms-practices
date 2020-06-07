#include<stdio.h>
int main()
{
    long long a[1000],res[1000],i,j,k=0,cas,l;
    while(scanf("%lld",&a[k++])==1&&a[k-1]);
    printf("PERFECTION OUTPUT\n");
    for(cas=0;cas<k-1;cas++)
    {
        long long sum=1,n=a[cas];j=0;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                res[j]=i;j++;
            }
        }
        for(i=0;i<j;i++)
        {
            sum+=res[i];
            if((n/res[i])>res[i])
            {
                sum+=(n/res[i]);
            }
        }

        //printf("sum %d\n",sum);
        if(sum==n)printf("%5lld  PERFECT\n",n);
        else if(sum>n) printf("%5lld  ABUNDANT\n",n);
        else if(sum<n) printf("%5lld  DEFICIENT\n",n);
    }
    printf("END OF OUTPUT");
    return 0;
}
