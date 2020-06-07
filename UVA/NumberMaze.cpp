#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<utility>

#define inf 99999999999999LL

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

using namespace std;

int n,m;
long long ar[1007][1007],dist[1007][1007];


struct Point{
    int f,s;
    Point(int a,int b)
    {
        f=a,s=b;
    }
    bool operator<(Point a) const
    {
        return dist[f][s] > dist[a.f][a.s];
    };
};

void dijk()
{
    for(int i=0;i<n+2;i++) for(int j=0;j<m+2;j++){dist[i][j]=inf;}
    priority_queue<Point> q;
    q.push(Point(1,1));
    dist[1][1]=ar[1][1];

    while(!q.empty())
    {
        Point u=q.top();q.pop();
        for(int i=0;i<4;i++)
        {
            int x=u.f+dx[i];
            int y=u.s+dy[i];

            if( ((x>=1&&x<=n)&&(y>=1&&y<=m)) && dist[x][y]>dist[u.f][u.s]+ar[x][y])
            {
                dist[x][y]=dist[u.f][u.s]+ar[x][y];
                q.push(Point(x,y));
            }
        }
    }
    return ;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%lld",&ar[i][j]);

        dijk();
        printf("%lld\n",dist[n][m]);
    }
    return 0;
}
/*
1
5 6
0 0 0 9 9 9
9 9 0 9 9 9
9 0 0 9 9 9
9 0 9 0 0 0
9 0 0 0 9 0
*/
