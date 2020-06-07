/*
 * Algorithm : Hungarian algorithm
 *             Max Weighted Bi-partite Matching
 * Complexity : O( N^3 )
 * Note : 0 base indexing
 */

#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back
#define MS( a ) memset( a,0,sizeof(a))
#define MSV( a,v ) memset( a,v,sizeof(a))

#define MAX 107          // Max number of vertices in one part
#define INF 100000000    // Just infinity

long Cost[MAX][MAX];      // Cost matrix
long N,Max_Match;         // N workers and N jobs
long lx[MAX], ly[MAX];    // Labels of X and Y parts
long xy[MAX];             // xy[x] - vertex that is matched with x,
long yx[MAX];             // yx[y] - vertex that is matched with y
bool S[MAX], T[MAX];     // Sets S and T in algorithm
long Slack[MAX];
long Slackx[MAX];         // Slackx[y] such a vertex, that
                         // l(Slackx[y]) + l(y) - w(Slackx[y],y) = Slack[y]
long Prev[MAX];           // Array for memorizing alternating paths

void Init_Labels(){
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    long x,y;
    for( x=0;x<N;x++ )
        for( y=0;y<N;y++ )
            lx[x] = max(lx[x], Cost[x][y]);
}

void Update_Labels(){
    long x, y, delta = INF;
    for( y=0;y<N;y++ ) if(!T[y]) delta = min(delta, Slack[y]);
    for( x=0;x<N;x++ ) if(S[x]) lx[x] -= delta;
    for( y=0;y<N;y++ ) if(T[y]) ly[y] += delta;
    for( y=0;y<N;y++ ) if(!T[y]) Slack[y] -= delta;
}

void Add_To_Tree(long x, long prevx) {
    S[x] = true;
    Prev[x] = prevx;
    long y;
    for( y=0;y<N;y++ )
        if (lx[x] + ly[y] - Cost[x][y] < Slack[y]){
            Slack[y] = lx[x] + ly[y] - Cost[x][y];
            Slackx[y] = x;
        }
}

void Augment(){
    if (Max_Match == N) return;
    long x, y, root;
    long q[MAX], wr = 0, rd = 0;
    memset(S, false, sizeof(S));
    memset(T, false, sizeof(T));
    memset(Prev, -1, sizeof(Prev));
    for( x=0;x<N;x++ )
        if (xy[x] == -1){
            q[wr++] = root = x;
            Prev[x] = -2;
            S[x] = true;
            break;
        }
    for( y=0;y<N;y++ ){
        Slack[y] = lx[root] + ly[y] - Cost[root][y];
        Slackx[y] = root;
    }
	while( true ){
        while (rd < wr){
            x = q[rd++];
            for( y=0;y<N;y++ ){
                if (Cost[x][y] == lx[x] + ly[y] &&  !T[y]){
                    if (yx[y] == -1) break;

                    T[y] = true;
                    q[wr++] = yx[y];

                    Add_To_Tree(yx[y], x);
                }
            }
            if (y < N) break;
        }
        if (y < N) break;
        Update_Labels();
        wr = rd = 0;
        for( y=0;y<N;y++ ){
            if (!T[y] &&  Slack[y] == 0){
                if (yx[y] == -1){
                    x = Slackx[y];
                    break;
                }
                else{
                    T[y] = true;
                    if (!S[yx[y]]){
                        q[wr++] = yx[y];
                        Add_To_Tree(yx[y], Slackx[y]);
                    }
                }
            }
        }
        if (y < N) break;
    }
    if (y < N){
        Max_Match++;
        for (long cx = x, cy = y, ty; cx != -2; cx = Prev[cx], cy = ty){
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        Augment();
    }
}

long Hungarian(){
    long x,Ret = 0;
    Max_Match = 0;
    memset(xy, -1, sizeof(xy));
    memset(yx, -1, sizeof(yx));
    Init_Labels();
    Augment();
    for( x=0;x<N;x++ )
        Ret += Cost[x][xy[x]];
    return Ret;
}


int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&Cost[i][j]);
            }
        }
        printf("Case %d: %ld\n",cas,Hungarian());
    }
    return 0;
}
