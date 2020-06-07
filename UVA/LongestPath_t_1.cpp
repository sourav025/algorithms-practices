#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

#define sz 109

int n,dis[sz],vis[sz],mx,nd;
vector<int> Edge[sz],topo;

void dfs(int src)
{
    for(int i=0;i<Edge[src].size();i++)
    {
        int v=Edge[src][i];
        if(dis[src]+1>dis[v])
        {
            dis[v]=dis[src]+1;
            dfs(v);
        }
    }
    mx=max(mx,dis[src]);
}

void reset()
{
    for(int i=0;i<109;i++) Edge[i].clear(),dis[i]=-1,vis[i]=0;
    topo.clear();
}

int main()
{
    int src,cas=1;
    while(scanf("%d",&n)==1&&n)
    {
        reset();
        scanf("%d",&src);
        int p,q;
        while(scanf("%d%d",&p,&q)==2&&p&&q)
            Edge[p].push_back(q);
        dis[src]=0;
        mx=-1,nd=1000;
        dfs(src);
        for(int i=1;i<=n;i++)
        {
            if(mx==dis[i])
            {
                mx=dis[i];
                nd=min(nd,i);
            }
            else if(mx<dis[i])
            {
                mx=dis[i],nd=i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cas++,src,mx,nd);
    }
    return 0;
}
/*
2
1
1 2
0 0
5
3
1 2
3 5
3 1
2 4
4 5
0 0
5
5
5 1
5 2
5 3
5 4
4 1
4 2
0 0
0
*/

