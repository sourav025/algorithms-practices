#include<stdio.h>
int main()
{
    int i,j,k,sum,pb[100000],n,total,res1,res2;
    while(scanf("%d",&n)==1&&n>=2)
    {
        int a=0,b=0,flag=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&pb[i]);
        }
        scanf("%d",&total);
        for(i=0;i<n-1;i++)
        {
            for(j=1;j<n;j++)
            {
                sum=pb[i]+pb[j];
                if(total==sum&&flag==0)
                {
                    a=pb[i];b=pb[j];
                    if(a>b)
                    {
                        int t=a;
                        a=b;b=t;
                    }
                    res1=b-a;
                    flag=1;
                }
                else if(total==sum&&flag==1)
                {
                    res2=pb[i]-pb[j];
                    if(res2<0)res2*=(-1);
                    if(res2<res1)
                    {
                        a=pb[i];b=pb[j];
                        if(a>b)
                        {
                            int t=a;
                            a=b;b=t;
                        }
                        res1=b-a;
                    }
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);
    }
    return 0;
}
