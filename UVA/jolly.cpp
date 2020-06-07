#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
using namespace std;
int main()
{
    int flag,a[5000],res[5000],i,j,k,l,n,m,count;
    while(scanf("%d",&n)==1&&n)
    {
        count=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            res[i]=abs(a[i]-a[i+1]);
        }
        sort(res,res+n-1);
        k=0;
        for(i=1;i<n;i++)
        {
            if(res[i-1]!=i)k++;
        }
        if(k==0)printf("Jolly\n");
        else printf("\nNot jolly\n");
    }
    return 0;
}
