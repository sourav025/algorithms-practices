#include<stdio.h>
#include<string.h>
#include<utility>
#include<queue>
using namespace std;

#define len 15
#define mk(a,b) make_pair(a,b)

int dx[]={1,0,-1,0,};
int dy[]={0,-1,0,1};

int n;
char grid[len][len];
int vis[len][len],cost[3][len][len],T;

int bfs(int j,pair<int,int> pos)
{
    cost[j][pos.first][pos.second]=0;

    queue<pair<int,int> > q;
    q.push(pos);
    while(!q.empty())
    {
        pair<int,int> u=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int x=u.first+dx[i];
            int y=u.second+dy[i];

            if( x>=0&&x<n && y>=0&&y<n && vis[x][y]!=T)
            {
                vis[x][y]=T;
                cost[j][x][y]=cost[j][u.first][u.second]+1;
                q.push(mk(x,y));
            }
        }
    }
}

pair<int,int> des[3];

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);

        T++;

        for(int i=0;i<n;i++) gets(grid[i]);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='X') des[i]=mk(i,j);

                if(grid[i][j]!= '.' && grid[i][j]!= '#' && vis[i][j]!=T )
                {
                    vis[i][j]=T;
                }
            }
        }
    }
    return 0;
}
