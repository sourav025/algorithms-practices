#include<bits/stdc++.h>
using namespace std;

int n,par[200];
map<string,int> mp;

struct Node{
    int a,b,c;
};

vector<Node> edges;

bool cmp(Node f,Node s)
{
    return f.c<s.c;
}

int findPar(int ch)
{
    if(par[ch]!=ch) return findPar(par[ch]);
    return par[ch];
}

void reset();

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        reset();
        scanf("%d",&n);int id=0;
        for(int i=0;i<n;i++)
        {
            string a1,b1;int c;
            cin>>a1>>b1>>c;
            if(mp.find(a1)==mp.end()) mp[a1]=id++;
            if(mp.find(b1)==mp.end()) mp[b1]=id++;

            Node node; node.a=mp[a1];node.b=mp[b1]; node.c=c;
            edges.push_back(node);
        }
        sort(edges.begin(),edges.end(),cmp);

        printf("Case %d: ",cas);

        int res=0;

        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i].a;
            int b=edges[i].b;
            int c=edges[i].c;

            int pa=findPar(a);
            int pb=findPar(b);


            if( pa != pb )
            {
                par[pb] = pa;
                res += c;
            }
        }
        set<int> st;st.clear();

        for(int i=0;i<id;i++)
            st.insert(findPar(i));

        if(st.size()==1)
            printf("%d\n",res);
        else printf("Impossible\n");

    }
    return 0;
}

void reset()
{
    for(int i=0;i<200;i++){
        par[i]=i;
    }
    mp.clear();
    edges.clear();
}
