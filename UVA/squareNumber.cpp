#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,n,l,a[100009],a1,b;
    for(i=0;i<=100000;i++)
    {
        n=sqrt(i);
        if(i==n*n){a[i]=1;}
    }
    while(scanf("%d%d",&a1,&b)==2&&(a1||b))
    {
        int count=0;
        for(i=a1;i<=b;i++)
        {
            if(a[i]==1)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
