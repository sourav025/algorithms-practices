#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int visited[50020];
int cont=0;
vector<int>v[50020];
void dfs(int n)
{
    int i;
    if(visited[n]==0)
    {
        visited[n]=1;
        for(i=0;i<v[n].size();i++)
        {
            dfs(v[n][i]);
        }
    }
}
int main()
{
    int i,j,k=1,l,r,e,a,b;

    while(scanf("%d%d",&r,&e)==2&&(r||e))
    {
        for(i=1;i<=e;i++)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int max=0,cont=0;
        for(i=1;i<=r;i++)
        {
            if(visited[i]==0)
            {
                dfs(i);
                cont++;
            }
        }
        printf("Case %d: %d\n",k++,cont);
        for(i=0;i<=r+10;i++)
        {
            visited[i]=0;
            v[i].clear();
        }
    }
    return 0;
}
