#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

#define MAX 1009

int n,m,k,T;
int par[MAX+7],par_dfs[MAX+7];
bool vis[MAX+7];
vector<int> Edge[MAX+7];

struct Node{
    int u,v,w;
    Node(int a=0,int b=0,int c=0)
    {
        u=a,v=b,w=c;
    }
    bool operator<(const Node &nd) const
    {
        return w<nd.w;
    }
}ar[10009];

void reset();

int find(int ch)
{
    if(par[ch]==ch) return ch;
    return find(par[ch]);
}

int bfs(int src)
{
    int cnt=1;
    queue<int> q;q.push_back(src);

    return cnt;
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        reset();
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ar[i]=Node(u,v,w);
        }
        int total=0;

        sort(ar,ar+m);

        for(int i=0;i<m;i++)
        {
            int up=find(ar[i].u);
            int vp=find(ar[i].v);
            if(up!=vp)
            {
                Edge[ar[i].u].push_back(ar[i].v);
                par[vp]=up;
                total+=ar[i].w;
            }
        }

        printf("Case %d: ",cas);

        else printf("impossible\n");
    }
    return 0;
}

void reset()
{
    for(int i=0;i<n+5;i++)
    {
        vis[i]=false;
        par[i]=i;
        Edge[i].clear();
    }
}

