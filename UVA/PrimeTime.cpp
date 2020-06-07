#include<stdio.h>
#include<string.h>

#define eps 1e-5
#define MAXSIEVE 100000002 // All prime numbers up to this
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5001 // sqrt(MAXSIEVE)/2
char a[MAXSIEVE/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7))) // Works when n is odd
//have to check for even numbers
void sieve()
{
        int i,j;
        memset(a,255,sizeof(a));
        a[0]=0xFE;
        for(i=1;i<MAXSQRT;i++)
                if (a[i>>3]&(1<<(i&7)))
                        for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
                                a[j>>3]&=~(1<<(j&7));
}


int main()
{
    sieve();
    int u,v;
    while(scanf("%d%d",&u,&v)==2)
    {
        double cnt=0.0;
        for(int i=u;i<v+1;i++)
        {
            int num=i*i+i+41;
            if((num&1)&&isprime(num))
                cnt=cnt+1.0;
        }

        double avg=(double)(v-u+1);
        avg = (cnt/avg)*100.0;
        printf("%.2lf\n",avg+eps);
    }
    return 0;
}
