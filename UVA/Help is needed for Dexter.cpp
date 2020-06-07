#include<stdio.h>
int main()
{
    long long n,count;
    while(scanf("%lld",&n)==1){
        count=0;
    while(n!=0)
    {
      count++;
      n/=2;
    }
    printf("%lld\n",count);
    }
    return 0;
}
