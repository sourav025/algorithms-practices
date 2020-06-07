#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define pb push_back

#define MAX 50050

vector<int> edge[MAX+7];
map<int,int> mp;

int vis[MAX+7],par[MAX+7],cost[MAX+7],T=1,src,des,n,ar[MAX+7];

void reset()
{
    for(int i=0;i<n+4;i++)
        par[i]=i,cost[i]=0,edge[i].clear(),ar[i]=0;
    mp.clear();
}

bool cmp(const int &a,const int &b){
    return ar[a]<ar[b];
}

//class cmp
//{
//    public: bool operator()(const int &a,const int &b)
//    {
//        if(cost[a]==cost[b]) return mp[a]>mp[b];
//        return cost[a]>cost[b];
//    };
//};

void setEdge(int u,int v)
{
    edge[v].push_back(u);
    edge[u].push_back(v);
}

void bfs()
{
    T++;
    queue<int> pq;
    pq.push(src);
    vis[src]=T;
    cost[src]=0;
    par[src]=src;
    while(!pq.empty())
    {
        int u=pq.front();pq.pop();
        if(u==des) return;
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(vis[v]!=T)
            {
                par[v]=u;vis[v]=T;
                cost[v]=cost[u]+1;
                pq.push(v);
            }
        }
    }
    return;
}

void print_path(int ch)
{
    if(par[ch]!=ch) print_path(par[ch]);
    if(ch==src) printf("%d",ar[ch]);
    else printf(" %d",ar[ch]);
}

int main()
{
    int t,u,v; scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);reset();
        int id=1;
        for(int i=1;i<=n;i++)
        {
            if(i==1) {scanf("%d",&u); mp[u]=id; ar[id]=u; u=id;id++; continue;}
            scanf("%d",&v);
            if(!mp[v]) {mp[v]=id; ar[id]=v;v=id;id++;}
            else v=mp[v];
            setEdge(u,v);
            u=v;
        }
        for(int i=1;i<id;i++){
            sort(edge[i].begin(),edge[i].end(),cmp);
            //printf("%d--> ",ar[i]);
            //for(int j=0;j<edge[i].size();j++) printf(" %d",ar[edge[i][j]]); printf("\n");
        }
        src=1,des=u;
        bfs();
        printf("Case %d:\n",cas);
        print_path(des);
        printf("\n");
    }
    return 0;
}
