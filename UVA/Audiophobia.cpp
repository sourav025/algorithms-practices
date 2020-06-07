#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 109
#define inf 999999999

vector<int> edge[MAX+7],cost[MAX+7];
int par[MAX+7],vis[MAX+7],n,m,q,T=1,dist[MAX+7];

struct Node{
    int u,v,c;
    Node(int uu=0,int vv=0,int cc=0)
    {
        u=uu,v=vv,c=cc;
    }
    bool operator<(const Node &nd)const
    {
        if(c==nd.c) {
            if(u==nd.u){
                return v<nd.v;
            }
            else return u<nd.u;
        }
        return c<nd.c;
    }
    void print()
    {
        printf("%d %d %d\n",u,v,c);
    }
};

///Find Parent for Kruskal's algo
int findPar(int ch)
{
    if(par[ch]!=ch)
        return findPar(par[ch]);
    return ch;
}

///Building a graph(MST)
void setEdge(int up,int vp,int c)
{
    edge[up].push_back(vp);
    cost[up].push_back(c);
    edge[vp].push_back(up);
    cost[vp].push_back(c);
}

///Finding the problem requirements
int bfs(int src,int des)
{
    T++;
    queue<int> q;
    q.push(src);
    dist[src]=0;
    vis[src]=T;

    while(!q.empty())
    {
        int u=q.front();q.pop();

        if(u==des) return dist[u];

        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(vis[v]!=T)
            {
                dist[v]=inf;
                vis[v]=T;
                dist[v]=min(dist[v],max(dist[u],cost[u][i]));
                q.push(v);
            }
        }
//        printf("\n");
    }
    return -1;
}

void reset()
{
    for(int i=0;i<n+5;i++)
        par[i]=i,edge[i].clear(),cost[i].clear(),dist[i]=inf;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","wt",stdout);
    int cas=1;
    while(scanf("%d%d%d",&n,&m,&q)==3)
    {
        if(n==0&&m==0&&q==0) break;
        if(cas>1) printf("\n");
        reset();
        vector<Node> extra;
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            //if(c<0) while(1);
            extra.push_back(Node(u,v,c));
        }
        sort(extra.begin(),extra.end());
//        printf("Now Sorted Order :\n");
        for(int i=0;i<m;i++)
        {
            Node ex=extra[i];
            int up=findPar(extra[i].u);
            int vp=findPar(extra[i].v);
            if(up!=vp)
            {
                //printf("up=%d vp=%d cost=%d\n",up,vp,ex.c);
                if(up<vp) par[vp]=up;
                else par[up]=vp;
                setEdge(up,vp,ex.c);
            }
        }

//        for(int i=1;i<=n;i++)
//        {
//            printf("%d->",i);
//            for(int j=0;j<edge[i].size();j++)
//            {
//                printf(" %d",edge[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
        printf("Case #%d\n",cas++);
        while(q)
        {
            q--;
            int s,d;
            scanf("%d%d",&s,&d);
            if(s<1||s>n || d<1||d>n) {printf("0\n");continue;}
            int res=bfs(s,d);
            if(res==-1)
            {
                printf("no path\n");
            }
            else printf("%d\n",res);
        }
    }
    return 0;
}

