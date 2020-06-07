#include<stdio.h>
#include<math.h>

int main()
{
	int t;scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		long long n;
		scanf("%lld",&n);
		n= n- (sqrt(n*1.0)) - ((sqrt(n/2.0)) );
		printf("Case %d: %lld\n",cas,n);
	}
}
