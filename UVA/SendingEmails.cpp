#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#include<queue>
#define INF 900000000
using namespace std;

vector<int>v[50009],cost[20009];
int dis[20009];

class cmp
{
    public : bool operator()(const int &s1,const int &s2)
    {
        return dis[s1]>dis[s2];
    }
};

int dijk(int src,int ds)
{
    priority_queue<int,vector<int>,cmp>Q;
    dis[src]=0;
    Q.push(src);
    while(!Q.empty())
    {
        int p=Q.top();
        if(p==ds) return dis[p];

        Q.pop();
        for(int i=0;i<v[p].size();i++)
        {
            int q=v[p][i];
            if(dis[q]>dis[p]+cost[p][i])
            {
                dis[q]=dis[p]+cost[p][i];
                Q.push(q);
            }
        }
    }
    return INF;
}
int main()
{
    int i,j,k=1,l,a,b,c,t,n,m,s,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>s>>d;
        for(i=0;i<=n;i++)
        {
            v[i].clear();
            cost[i].clear();
            dis[i]=INF;
        }
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            v[a].push_back(b);
            v[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        int cst=dijk(s,d);
        printf("Case #%d: ",k++);
        if(cst==INF)
        {
            printf("unreachable\n");
        }
        else             printf("%d\n",cst);

    }
    return 0;
}

