#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
vector <int> v1[1000000],v2[1000000],res;
int vis[1000000],cnt,com[1000000],ans[1000000];
void reset(int n)
{
    for(int i=0;i<=n;i++)
    {
        com[i]=0;
        ans[i]=0;
        //in[i]=0;
        v1[i].clear();
        v2[i].clear();
    }
}
void dfs1(int src)
{
    vis[src]=1;
    for(int i=0;i<v1[src].size();i++)
    {
        if(vis[v1[src][i]]==0)
        {
            dfs1(v1[src][i]);
        }
    }
    res.push_back(src);
}
void dfs2(int n, int c)
{
    vis[n]=0;
    com[n]=c;
    for(int i=0;i<v2[n].size();i++)
    {
        if(vis[v2[n][i]]==1)
        {
            dfs2(v2[n][i],c);
        }
    }
}
int main()
{
    int i,k,l,t,c,n,m,a,b;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d%d",&n,&m);
        reset(n);
        cnt=0;
        int c=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            v1[a].push_back(b);
            v2[b].push_back(a);
        }
        for(i=1;i<=n;i++)
        {
            if(vis[i]!=1)
            {
                dfs1(i);
            }
        }
        for(i=res.size()-1;i>=0;i--)
        {
            if(vis[res[i]]==1)
            {
                dfs2(res[i],++c);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(int j=0;j<v1[i].size();j++)
            {
                if(com[i]!=com[v1[i][j]])
                {
                    ans[com[v1[i][j]]]++;
                }
            }
        }
        for(i=1;i<=c;i++)
        {
            if(!ans[i])
            cnt++;
        }
        printf("%d\n",cnt);
        t--;
    }
    return 0;
}
