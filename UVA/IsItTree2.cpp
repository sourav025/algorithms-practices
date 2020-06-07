#include<iostream>
#include<cstdio>
#include<set>
#include<utility>
using namespace std;

set< pair<int,int> > st;
int cnt;
set<int> nodes;


int main()
{
    int cas=1,u,v;
    while( scanf("%d%d",&u,&v)==2&&v>=0&&u>=0 )
    {
        if(u==0&&v==0){
            printf("Case %d is not a tree.\n",cas++);continue;
        }
        nodes.clear(),st.clear();
        nodes.insert(u);nodes.insert(v);
        if(u!=v) st.insert(make_pair(u,v));
        while(scanf("%d%d",&u,&v)==2&&v>0&&u>0)
        {
            if(u!=v){
                nodes.insert(u);nodes.insert(v);
                st.insert(make_pair(u,v));
            }
        }

        int nn=nodes.size();
        int edges=st.size();

        if(nn-1==edges)
        {
            printf("Case %d is a tree.\n",cas++);
        }
        else printf("Case %d is not a tree.\n",cas++);

    }
    return 0;
}
