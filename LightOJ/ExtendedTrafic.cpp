#include<bits/stdc++.h>
using namespace std;

#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)

#define MAX 300
#define inf (1<<27)

int busy[MAX+7],dis[MAX+7],q,k,n,t,e;
vector<pair<int,int> > edges;


void bellmanFord()
{

    for(int i=0;i<MAX+7;i++) dis[i]=inf;

    dis[1]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=edges[j].first;
            int v=edges[j].second;

            if(dis[u]==inf) continue;


//            printf("(%d->%d) (%d - %d)\n",u,v,busy[u],busy[v]);
            int c=busy[v]-busy[u];
            c=(c*c*c);
            if(dis[u]+c<dis[v])
            {
                dis[v]=dis[u]+c;
//                printf("\t%d) %d\n",v,dis[v]);
            }
        }
    }

    for(int j=0;j<e;j++)
    {
        int u=edges[j].first;
        int v=edges[j].second;

        int c=busy[v]-busy[u];
        c=(c*c*c);
        if(dis[u]+c<dis[v])
        {
            dis[v]=-1;
        }
    }
}


int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++){scanf("%d",&busy[i]);}
        scanf("%d",&e);

        for(int i=1;i<=e;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
            edges.pb(mk(u,v));
        }

        bellmanFord();

        scanf("%d",&q);

        printf("Case %d:\n",cas);
        while(q--)
        {
            scanf("%d",&k);
            if(dis[k]==inf||dis[k]<3)
            {
                printf("?\n");
            }
            else printf("%d\n",dis[k]);

        }
        edges.clear();
    }
    return 0;
}

/*
2
5
6 7 8 9 10
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5
2
10 10
1
1 2
1
2
*/
