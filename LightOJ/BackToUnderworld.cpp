#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#include<map>
using namespace std;

#define max(a,b) ((a>b)?(a):(b))

int color[30000],n,black,white,T;
vector<int> Edge[30000];
map<int,int> mp;

void reset(int id)
{
    for(int i=0;i<id+5;i++)
        Edge[i].clear(),color[i]=0;
    mp.clear();
}

int bfs(int src)
{
//    printf("***********************************\n");
    black=0,white=0;
    queue<int>q;q.push(src);
    color[src]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(color[u]==1) black++;
        else white++;
//        printf("\nsrc : %d -> ",u);
        for(int i=0;i<Edge[u].size();i++)
        {
            int v=Edge[u][i];
            if(color[v]==0)
            {
//                printf("%d ,",v);
                color[v]=(color[u]==1?2:1);
                q.push(v);
            }
        }
    }
    return max(black,white);
}

int main()
{
    int t,u,v;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        int id=1;mp.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            if(mp[u]==0)
                mp[u]=id++;
            if(mp[v]==0)
                mp[v]=id++;

            u=mp[u];v=mp[v];

            Edge[u].push_back(v);
            Edge[v].push_back(u);

//            printf("Edge (%d-%d)\n",u,v);

        }

        int mx=0;T=1;
        for(int i=1;i<id;i++)
        {
            if(color[i]==0)
            {
                int ret=bfs(i);
                    mx+=ret;
            }
        }
        printf("Case %d: %d\n",cas,mx);
        reset(id);
    }
    return 0;
}
