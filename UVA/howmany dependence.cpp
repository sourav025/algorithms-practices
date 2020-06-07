#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n,vis[10000],cnt,ext[10000],p;
vector<int>v[10000];
void dfs(int src)
{
    if(vis[src]==0)
    {
        vis[src]=1;cnt++;ext[p++]=src;
        for(int i=0;i<v[src].size();i++)
        {
            if(vis[v[src][i]]==0){

            dfs(v[src][i]);}
        }
    }
    else return;
    return;
}
int main()
{
    int i,j,k,a,b,l,t;
    while(scanf("%d",&n)==1&&n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            while(t!=0)
            {
                scanf("%d",&a);
                v[i].push_back(a);
                t--;
            }
        }
        int max=0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                cnt=0;p=0;
                dfs(i);
                for(k=0;k<p;k++){vis[ext[k]]=0;}
            }
            if(cnt>max){max=cnt;l=i;}
        }
        printf("%d\n",l);
        for(i=0;i<n+3;i++){vis[i]=0;v[i].clear();}

    }
    return 0;
}
