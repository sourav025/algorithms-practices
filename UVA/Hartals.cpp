#include<stdio.h>
int day[1000000];
int main()
{
    int n,t,d,i,a,j,k;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++)
    {
        scanf("%d%d",&d,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            k=a;
            while(k<=d)
            {
                day[k]=1;
                k+=a;
            }
        }
        int cnt=0;
        for(i=0;i<=d;i++)
        {
            if(day[i]==1&&i%7!=0&&i%7!=6)
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(i=0;i<d+3;i++)
        day[i]=0;
    }
    return 0;
}
