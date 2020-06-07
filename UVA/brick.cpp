#include<stdio.h>
int main()
{

    int wall[150],i,j,k=1,n,avg,ext;
    while(scanf("%d",&n)==1&&n)
    {
        int sum=0,ext=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&wall[i]);
            sum=sum+wall[i];
        }
        avg=sum/n;
        for(j=0;j<n;j++)
        {
            if(wall[j]>avg)
            {
                ext=ext+(wall[j]-avg);
                //wall[j]=avg;
            }
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n",k,ext);
        k++;
    }
    return 0;
}
