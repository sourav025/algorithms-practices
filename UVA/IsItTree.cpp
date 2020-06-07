#include<cstdio>
#include<set>
#include<iostream>
#include<utility>
#include<map>
#include<list>
using namespace std;

typedef pair<int,int> Node;
#define mp(a,b) make_pair(a,b)

set<Node> edge;
map<int,int> in,out;
set<int> src;

int main()
{
    int u,v,cas=1;
    while( scanf("%d%d",&u,&v)==2&&v>=0&&u>=0 )
    {
        out.clear(),in.clear(),src.clear(),edge.clear();
        int flag=1;

        if(u==v) {
            if(u==0&&v==0) {printf("Case %d is not a tree.\n",cas++);continue;}
            else flag=0;
        }

        out[u]++;
        in[v]++;
        src.insert(u);

        while(scanf("%d%d",&u,&v)==2&&(u||v)){
            if(!flag) continue;
            if(edge.find(mp(v,u))!=edge.end() ) {flag=0;continue;}

            if(edge.find(mp(u,v))==edge.end()){
                edge.insert(mp(u,v));
                out[u]++;
                in[v]++;
                src.erase(v);
                if(in[u]==0) src.insert(u);
                if(in[v]>1) flag=0;
            }
        }

//        //Printing Src List
//        cout<<"\n\nSources Degrees "<<endl;
//        for(set<int>::iterator it=src.begin();it!=src.end();it++){
//            cout<<(*it)<<endl;
//        }
//
//        //Printing outDegree
//        cout<<"\n\nOut Degrees "<<endl;
//        for(map<int,int>::iterator it=out.begin();it!=out.end();it++){
//            cout<<(*it).first<<"  "<<(*it).second<<endl;
//        }
//
//
//        //Printing inDegree
//        cout<<"\n\nIn Degrees "<<endl;
//        for(map<int,int>::iterator it=in.begin();it!=in.end();it++){
//            cout<<(*it).first<<"  "<<(*it).second<<endl;
//        }
//        cout<<"\n\n";


        printf("Case %d is ",cas++);
        if(src.size()!=1) flag=0;
        if(!flag){
            printf("not a tree.\n");
        }
        else printf("a tree.\n");
    }
    return 0;
}
/*

1 2
2 3
4 3
2 4
0 0
1 2
2 3
4 5
0 0
1 7346537
37542 1
0 0
7 7
0 0
8 9
0 5
0 0
100 1
1 2
9 7
7 3
3 88
88 6
1 9
2 6
0 0
1 2
1 2
0 0
999999 5
0 0
0 0
-1 -1
*/
