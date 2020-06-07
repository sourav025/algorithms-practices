#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#define INF 900000000
using namespace std;

#define SZ 120

int dis[SZ];
int n,m;
vector<int>edge[SZ],cost[SZ];

class cmp
{
    public : bool operator()(const int &s1,const int &s2)
    {
        return dis[s1]>dis[s2];
    }
};

void dijk()
{
    priority_queue<int,vector<int>,cmp>Q;
    dis[1]=0;Q.push(1);
    while(!Q.empty())
    {
        int u=Q.top();
        Q.pop();
        for(int i=0;i<edge[u].size();i++) {
            int v=edge[u][i];
            if(dis[v]>dis[u]+cost[u][i]) {dis[v]=dis[u]+cost[u][i];Q.push(v);}
        }
    }
}

void reset()
{
    for(int i=0;i<n+10;i++)
    {
        edge[i].clear(),cost[i].clear(),dis[i]=INF;
    }
}

int main()
{
    int t,a,b,c;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);
        reset();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }

        printf("Case %d: ",cas);
        dijk();
        if(dis[n]<INF) printf("%d\n",dis[n]);
        else printf("Impossible\n");
    }
    return 0;
}
