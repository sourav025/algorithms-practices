#include<stdio.h>
#include<math.h>

using namespace std;

int n;

int main()
{
    int t;
    scanf("%d",&t);

    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        int sq=sqrt(n);
        long long res=0;
        for(int i=1;i<=sq;i++)
        {
            res+=(long long)(n/i);
        }
        res=(res<<1)-(sq*sq);
        printf("%lld\n",res);
    }
    return 0;
}
