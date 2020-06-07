#include<stdio.h>
#include<string.h>
#include<utility>
#include<queue>
#include<iostream>
using namespace std;

#define mk(a,b) make_pair(a,b)

#define len 55

int n,m;

char grid[len][len];
int charVis[len],T;
bool vis[len][len];

int dx[]={1,0,-1,0,};
int dy[]={0,-1,0,1};

void filling(char ch)
{
    memset(vis,false,sizeof(vis));
    queue<pair<int,int> >q;

    for(int i=0;i<m;i++)
    {
        if(grid[0][i]!=ch) { q.push(mk(0,i)); vis[0][i]=true; }
        if(grid[n-1][i]!=ch){ q.push(mk(n-1,i)); vis[n-1][i]=true; }
    }

    for(int i=1;i<n-1;i++)
    {
        if(grid[i][0]!=ch) { q.push(mk(i,0)); vis[i][0]=true; }
        if(grid[i][m-1]!=ch){ q.push(mk(i,m-1)); vis[i][m-1]=true; }
    }

    while(!q.empty())
    {
        pair<int,int> p=q.front();q.pop();

        for(int i=0;i<4;i++)
        {
            int x=p.first+dx[i];
            int y=p.second+dy[i];

            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]!=ch)
            {
                vis[x][y]=true;
                q.push(mk(x,y));
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j])
                grid[i][j]=ch;
        }
    }
}

int main()
{
    T=10;
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&m);T++;
        getchar();
        for(int i=0;i<n;i++) gets(grid[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='.'&& charVis[grid[i][j]-'A']!=T)
                {
                    charVis[grid[i][j]-'A']=T;
                    filling(grid[i][j]);
                }
            }
        }
        printf("Case %d:\n",cas);
        for(int i=0;i<n;i++){
            puts(grid[i]);
        }
    }
    return 0;
}

/*
1
4 4
.A..
A.A.
A.A.
AAA.


5 5
..A..
.A.A.
.BA..
B.B..
.B...


2
5 5
AAAEE
ABAHE
A.AHF
AAAHF
.G...
20 20
....................
...B................
..BBBB..............
..B..BBB............
.BB....B............
BBB..RRBBBBBBBBBB...
BBB..RR....SS.BBB...
.BB..RR....SSBB.....
..B..RR.DD.BBB......
.BB..KMDDD.B........
..BB.KDD...B..BBB...
...B.KK....BBBBBB...
..BB.KK....BBBCBB...
...B.KK...BB.BCB....
...B.K..BBB..BCBB...
...BBBBBB....BBBB...
...BBBBBBB....BBB...
...............BB...
................BB..
.................B..

*/
