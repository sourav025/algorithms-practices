#include<stdio.h>

long long ar[100009],sum,n,q;
void pre()
{
    sum=0;
    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&ar[i]);
        sum+=(((n-1)-(2LL*i))*ar[i]);
    }
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        printf("Case %d:\n",cas);
        scanf("%lld%lld",&n,&q);
        pre();
        while(q--)
        {
            int qr;
            scanf("%d",&qr);
            if(qr==0)
            {
                long long pos,val;
                scanf("%lld%lld",&pos,&val);
                long long exPos=((n-1)-(2*pos));
                sum-=(ar[pos]*((n-1)-(2*pos)));
                ar[pos]=val;
                sum+=(ar[pos]*((n-1)-(2*pos)));
            }
            else
            {
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}
