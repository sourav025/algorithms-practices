//Backtrack for tri coloring a graph
#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;
int vis[1000],graphNo[1000],comp[1000];

bool notGo[1000];

bool flag=false;
vector<int> Edge[1000],topo;
int color=3,n,m,coun;
int cntCol=0;


void GF(int src)
{
    if(vis[src]==0)
    {
        comp[src]=coun;
        vis[src]=1;
        for(int i=0;i<Edge[src].size();i++)
        {
            GF(Edge[src][i]);
        }
        topo.push_back(src);
    }
}

map<int,string>mp;

bool dfs(int src,int cnt)
{
    if(flag) return flag;
    //if(cnt>0) printf("\nCount is : %d\n",cnt);
    if(!notGo[src]&&cnt==graphNo[comp[src]]-1)
    {
        //printf("Get Into BreakIF\n");
        for(int i=0;i<n;i++)
        {
            if(comp[i]==comp[src]){
                printf("%d) color : ",i);
                notGo[i]=true;
                cout<<mp[vis[i]]<<endl;
            }
        }
        return flag;
    }
    for(int i=0;i<Edge[src].size();i++)
    {
        int v=Edge[src][i];
        if(vis[v]==0)
        {
            if(!flag&&vis[src]==1)
            {
                vis[v]=2;
                dfs(v,cnt+1);
                if(!flag){
                vis[v]=3;
                dfs(v,cnt+1);}
            }
            else if(!flag&&vis[src]==2)
            {
                vis[v]=3;
                dfs(v,cnt+1);
                if(!flag){
                vis[v]=1;
                dfs(v,cnt+1);}
            }
            else if(!flag&&vis[src]==3)
            {
                vis[v]=2;
                dfs(v,cnt+1);
                if(!flag){
                vis[v]=1;
                dfs(v,cnt+1);}
            }
            vis[v]=0;
        }
        if(flag) return flag;
    }
    return flag;
}

int main()
{
    mp[1]="Red",mp[2]="Green",mp[3]="Blue";
    scanf("%d%d",&n,&m);
    memset(vis,0,n+3);
    memset(notGo,false,sizeof(notGo));
    for(int i=0;i<m;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }
    coun=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            GF(i);
            graphNo[coun]=topo.size();coun++;
            topo.clear();
        }
    }

    memset(vis,0,n+3);
    flag=false;
    for(int i=0;i<n;i++)
    {
        if(!notGo[i])
        {
            if(!flag)
            {
                vis[i]=1;
                dfs(i,0);
            }
            else if(!flag)
            {
                vis[i]=2;
                dfs(i,0);
            }
            else if(!flag)
            {
                vis[i]=3;
                dfs(i,0);
            }

            vis[i]=0;
        }
    }
    return 0;
}
