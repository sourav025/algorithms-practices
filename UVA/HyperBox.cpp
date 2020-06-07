
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long Long;

Long dim[20],fib[55];

void pre()
{
    fib[0]=1LL;fib[1]=2LL;
    for(int i=2;i<=50;i++)
        fib[i]=fib[i-1]+fib[i-2];
}

int main()
{
    pre();
    int t,n;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&dim[i]);
        }
        Long cnt[20];memset(cnt,0LL,sizeof(cnt));
        for(int j=0;j<n;j++)
        {
            for(int i=50;i>=0;i--)
            {
                while(dim[j]>=fib[i])
                {
                    dim[j]-=fib[i];
                    cnt[j]++;
                }
            }
        }

        Long min=1LL;
        for(int i=0;i<n;i++)
        {
            min*=cnt[i];
        }
        cout<<"Case "<<cas<<": "<<min<<endl;
    }
    return 0;
}
