#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

#define sz 109

int n,dis[sz],vis[sz];
vector<int> Edge[sz],topo;

void dfs(int src)
{
    vis[src]=1;
    for(int i=0;i<Edge[src].size();i++)
    {
        if(vis[Edge[src][i]]==0)
            dfs(Edge[src][i]);
    }
    topo.push_back(src);
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

        dfs(src);dis[src]=0;
        int mx=-1,nd=1000;
        for(p=topo.size()-1;p>=0;p--)
        {
            int u=topo[p];
            for(int i=0;i<Edge[u].size();i++)
            {
                int v=Edge[u][i];
                if(dis[u]+1>=dis[v]) dis[v]=dis[u]+1;

                if(mx==dis[v] && v<nd) nd=v;
                else if(dis[v]>mx) mx=dis[v],nd=v;
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
