#include<stdio.h>
int main()
  {
	int i,n,k,ext,t,h,m;
    scanf("%d",&t);
    for(ext=1;ext<=t;ext++)
    {
        scanf("%d%d%d",&n,&m,&k);
        h=n+m;
        int count=0;
        while(h>=k&&k>1)
        {
          count++;
          h-=k;h++;
        }
        printf("%d\n",count);
    }
    return 0;
}
