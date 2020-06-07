#include<stdio.h>

struct Point{
    int x,y;
    Point(int a=0,int b=0)
    {
        x=a,y=b;
    }
}ar[1000];

bool onLin(Point a,Point b,Point c)
{
    int area=a.x*(b.y-c.y)+b.x*(c.y-a.y) + c.x*(a.y-b.y);
    return (area==0)?1:0;
}

int main()
{
    int t,n;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        printf("Case %d: ",cas);
        if(n==1||n==2) {printf("%d\n",n);continue;}

        for(int i=0;i<n;i++)
            scanf("%d%d",&ar[i].x,&ar[i].y);

        int max=2;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int cnt=2;
                for(int k=j+1;k<n;k++)
                {
                    if(onLin(ar[i],ar[j],ar[k]))
                        cnt++;
                }
                if(cnt>max) max=cnt;
            }
        }
        printf("%d\n",max);
    }

    return 0;
}
