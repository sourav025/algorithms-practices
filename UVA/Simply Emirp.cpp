#include<stdio.h>
long long prime[1000009];
long long rev(long long a)
{
    long long n=0;
    while(a>0)
    {
        n=(n*10)+(a%10);
        a=a/10;
    }
    return n;
}
int main()
{
    long long i,j,k,l,n,n1;
    prime[1]=0;
    for(i=2;i<1000009;i++)
    {
        if(prime[i]!=1)
        {
            for(j=i+i;j<1000009;j+=i)
            prime[j]=1;
        }
    }
    while(scanf("%lld",&n)==1)
    {
        if(n!=0){
        n1=rev(n);
        printf("%lld is ",n);
        if(n==1||prime[n]!=1&&prime[n1]||n1==n)
        {
            printf("prime.\n");
        }
        else if(prime[n1]!=1)
        {
            printf("emirp.\n");
        }
        else if(prime[n])
        printf("not prime.\n");}
    }
    return 0;
}
