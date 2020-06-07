#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

char str[50][100];

int r,lens[50];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};

bool bound(int x,int y)
{
    return (x>=0 && y>=0);
}

void bfs(pair<int,int> st)
{
    queue<pair<int,int> > q;
    q.push(st);
    while(!q.empty())
    {
        pair<int,int> p=q.front(); q.pop();

        str[p.first][p.second]='#';

        for(int i=0;i<4;i++)
        {
            int x1=p.first+dx[i];
            int y1=p.second+dy[i];

            if( bound(x1,y1) && str[x1][y1]==' ')
                q.push(make_pair(x1,y1));
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int __test;
    scanf("%d",&__test);
    getchar();
    for(int _c=1;_c<=__test;_c++)
    {
        r=0;

        pair<int,int> startPos=make_pair(-1,-1);

        memset(str,'\0',sizeof(str));
        memset(lens,0,sizeof(lens));

        while(gets(str[r]))
        {
            if(str[r][0]=='\0') break;

            if(str[r][0]=='_')
            {
                lens[r]=strlen(str[r]);
                r++;
                break;
            }

            lens[r]=strlen(str[r]);
            if( startPos.first==-1 && startPos.second==-1 )
                for(int i=0;i<lens[r];i++)
                {
                    if(str[r][i]=='*')
                    {
                        startPos=make_pair(r,i);break;
                    }
                }
            r++;
        }

        if(startPos.first>-1 && startPos.second>-1 )
            bfs(startPos);

        for(int i=0;i<r;i++)
            puts(str[i]);
    }
    return 0;
}
/*

3
XXXXXXXXX
X   X   X
X   *   X
X   X   X
XXXXXXXXX
X   X
X   X
X   X
XXXXX
_____
XXXXX
X   X
X * X
X   X
XXXXX
_____
XXXXXXXXXXXXXXXXXXXXX
X   X   X   X   X   X
X           X   X   X
X   X   X   X   X   X
XXXXXX XXX XXXXXXXXXX
X   X   X   X   X   X
X   X     *     X   X
X   X   X   X   X   X
XXXXXXXXXXXXXXXXXXXXX
_____________________

*/
