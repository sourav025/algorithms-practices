///Not AC


#include<bits/stdc++.h>
using namespace std;

#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)

#define MAX 1500
#define inf (1<<27)

bool hasResult;
int dis[MAX+7],n,m,t;
vector<pair<int,int> > edges;
vector<int> cost;


void bellmanFord()
{
    hasResult=true;
    for(int i=0;i<MAX+7;i++) dis[i]=inf;

    dis[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=edges[j].first;
            int v=edges[j].second;

            if(dis[u]==inf) continue;

//            printf("(%d->%d) (%d - %d)\n",u,v,busy[u],busy[v]);
            if(dis[u]+cost[j]<dis[v])
            {
                dis[v]=dis[u]+cost[j];
//                printf("\t%d) %d\n",v,dis[v]);
            }
        }
    }

    int cnt=0;
    for(int j=0;j<m;j++)
    {
        int u=edges[j].first;
        int v=edges[j].second;
        if(dis[u]+cost[j]<dis[v])
        {
            cnt++;
            dis[v]=dis[u]+cost[j];
        }
    }
    printf("Real Count : %d\n",cnt);
}


int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);

        for(int i=0;i<m;i++)
        {
            int u,v,c;scanf("%d%d%d",&u,&v,&c);
            edges.pb(mk(u,v));
            cost.pb(c);
        }

        bellmanFord();

        printf("Case %d: %d\n",cas,hasResult);

        edges.clear();cost.clear();
    }
    return 0;
}

