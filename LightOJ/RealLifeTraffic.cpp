#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>

#define getMin(a,b) ((a<b)?(a):(b))
#define getMax(a,b) ((a>b)?(a):(b))
#define MAX 100009
using namespace std;

typedef pair<int,int> pn;

vector<int>edge[MAX];
int dc,n,m;
int disTime[MAX+7],level[MAX+7],degree[MAX+7];

void reset();

void addEdge(int u,int v);

void dfsCont(int u,int par);

void fillUpDegree();

int getAns();

int main()
{
    int t,cas=1,a,b;
    for(scanf("%d",&t);cas<=t;cas++)
    {
        dc=1;
        scanf("%d%d",&n,&m);
        reset();
        for(int i=0;i<m;i++)
            scanf("%d%d",&a,&b),addEdge(a,b);
        dfsCont(0,0);
        fillUpDegree();
        int res=getAns();
        printf("Case %d: %d\n",cas,res);

    }
    return 0;
}

void reset()
{
    for(int i=0;i<n+5;i++)
    {
        edge[i].clear(),disTime[i]=0,level[i]=0,degree[i]=0;
    }
}

void addEdge(int u,int v)
{
    edge[u].push_back(v);
    edge[v].push_back(u);
}

void dfsCont(int u,int par)   //DFS counting
{
    disTime[u]=level[u]=dc++;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==par) continue;
        if(disTime[v]==0)
        {
            dfsCont(v,u);
            level[u]=getMin(level[u],level[v]);
        }
        else if(level[u]>level[v])
        {
            level[u]=level[v];
        }
    }
}

void fillUpDegree()
{
    for(int u=0;u<n;u++)
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(level[u]!=level[v])  // a bridge Bridge
                degree[level[u]]++;
        }
}

int getAns()
{
    int cnt=0;
    for(int i=0;i<=n;i++)
        if(degree[i]==1)
            cnt++;
    return (cnt+1)/2;
}
