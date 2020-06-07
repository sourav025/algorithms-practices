#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

#define MAX 30009
#define pb push_back

int fin[MAX+7],ex[MAX+7],vis[MAX+7],n,m,T;
vector<int> edge[MAX+7],cost[MAX+7];

void add(int u,int v,int c)
{
    edge[u].pb(v);
    edge[v].pb(u);
    cost[u].pb(c);
    cost[v].pb(c);
}

void bfs(int src)
{
    T++;
    int u;
    queue<int> q;
    int s=0,mv=0;
    for(int id=0;id<3;id++)
    {
        vis[src]=T;ex[src]=0,q.push(src);
        while(!q.empty())
        {
            u=q.front();q.pop();
            for(int i=0;i<edge[u].size();i++)
            {
                int v=edge[u][i];
                if(vis[v]!=T)
                {
                    vis[v]=T;
                    ex[v]=ex[u]+cost[u][i];
                    fin[v]=max(fin[v],ex[v]);
                    if(fin[v]>=mv){
                        mv=fin[v],s=v;
                    }
                    q.push(v);
                }
            }
        }
        src=s,T++;
        mv=0;
    }
}

int main()
{
    T=1;
    int t,u,v,c;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            add(u,v,c);
        }
        bfs(0);
        printf("Case %d:\n",cas);
        for(int i=0;i<n;i++)
        {
            printf("%d\n",fin[i]);
            edge[i].clear(),cost[i].clear(),fin[i]=0;
        }
    }
    return 0;
}
