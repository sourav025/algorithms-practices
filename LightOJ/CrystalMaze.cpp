#include<stdio.h>
#include<queue>
using namespace std;

struct Node{
    int x,y;
    Node(int xx=0,int yy=0)
    {
        x=xx,y=yy;
    }
};

int n,m,q,T,vis[509][509];
char ar[509][509];

int dx[]={0,0 , 1, -1};
int dy[]={1,-1, 0 , 0};

int bfs(Node src)
{
    T++;
    queue<Node> q;
    q.push(src);
    vis[src.x][src.y]=T;
    int cnt=(ar[src.x][src.y]=='C'?1:0);
    while(!q.empty())
    {
        Node u=q.front();q.pop();
        printf("Now : %d %d\n",u.x,u.y);
        for(int i=0;i<4;i++)
        {
            Node v=Node(u.x+dx[i],u.y+dy[i]);

            if( v.x>=0 && v.x<n && v.y>=0 && v.y<m && vis[v.x][v.y]!=T && ar[v.x][v.y]!='#' )
            {
                if(ar[v.x][v.y]=='C')
                    cnt++;
                vis[v.x][v.y]=T;
                q.push(v);
            }
        }
    }
    return cnt;
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d",&n,&m,&q);getchar();
        for(int i=0;i<n;i++)
            gets(ar[i]);
        printf("Case %d:\n",cas);
        Node src;
        while(q--)
        {
            scanf("%d%d",&src.x,&src.y);
            src.x--,src.y--;
            printf("%d\n",bfs(src));
        }
    }
    return 0;
}
/*
1
4 5 2
..#..
.C#C.
##..#
..C#C
1 1
4 1
*/
