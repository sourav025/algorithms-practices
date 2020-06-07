#include<stdio.h>
int main()
{
    int ara[10000],n,t,i,j,k,count;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d",&n);
        count=0;
        for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(ara[j]>ara[j+1])
            {
                count++;
                int temp=ara[j];
                ara[j]=ara[j+1];
                ara[j+1]=temp;
            }
        }
    }
    printf("Optimal train swapping takes %d swaps.\n",count);
    }
    return 0;
}
