#include<bits/stdc++.h>
using namespace std;

#define mk(a,b) make_pair(a,b)

typedef pair<int,int> Point;
int T,n,m,vis[30][30];
char grid[30][30];

int dx[]={0, 0,1,-1 };
int dy[]={1,-1,0,0 };

int bfs(Point &st)
{
    T++;
    queue<Point> q;
    q.push(st);
    vis[st.first][st.second]=T;
    int cnt=1;
    while(!q.empty())
    {
        Point p=q.front();
                q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.first+dx[i];
            int y=p.second+dy[i];
            if(x>=0&&y>=0&&x<n&&y<m && vis[x][y]!=T && grid[x][y]=='.')
            {
                vis[x][y]=T;
                cnt++;
                q.push(mk(x,y));
            }
        }
    }
    printf("%d\n",cnt);
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&m,&n);getchar();

        Point start;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                scanf("%c",&grid[i][j]);
                if(grid[i][j]=='@')
                    start=mk(i,j);
            }
            getchar();
        }
//        cout<<start.first<<" , "<<start.second<<endl;
        printf("Case %d: ",cas);
        bfs(start);
    }
    return 0;
}
/*
4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/
