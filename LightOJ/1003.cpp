#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

#define MAX 20509

map<string,int> mp;
vector<int> Edge[MAX+7];

int n;
int vis[MAX+7];

bool isCycle=false;

void dfs(int src)
{
    if(isCycle) return ;

    for(int i=0;i<Edge[src].size();i++)
    {
        int v=Edge[src][i];

        if(vis[src]==vis[v]) {isCycle=true; break;}
        if(vis[v]==v)
        {
            vis[v]=vis[src];
            dfs(v);
        }
    }
}

int main()
{
    int t,id;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        isCycle=false;
        cin>>n;
        id=1;

        for(int i=0;i<2*n+5;i++) vis[i]=i,Edge[i].clear();id=1;
        mp.clear();

        for(int i=0;i<n;i++)
        {
            string u,v;
            cin>>u>>v;
            if(!mp[u]) mp[u]=id++;
            if(!mp[v]) mp[v]=id++;
            Edge[mp[u]].push_back(mp[v]);
        }

//        for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
//        {
//            cout<<(*it).first<<" --> "<<(*it).second<<endl;
//        }

        for(int i=1;i<id;i++)
        {
            if(vis[i]==i)
                dfs(i);
        }
        cout<<"Case "<<cas<<": ";
        if(isCycle) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
/*
1
3
soda wine
water wine
wine water
*/
