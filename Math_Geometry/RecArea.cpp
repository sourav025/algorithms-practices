/* Findin Area of rectangle */
/* line sweep + segment tree */
/* O( nlogn ) */
/* HDU 3265 */

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 50000
#define pb push_back

struct LINE{
    long y1,y2;
    bool IsLeft;
    LINE( long y1,long y2,bool b )
    {
        this->y1 = y1;
        this->y2 = y2;
        IsLeft = b;
    }
};

vector<LINE> v[MAX+7];
long N;
long Node[10*MAX+7];
long Cover[10*MAX+7];

void Update( long n,long l,long r,long p,long q )
{
    if( p>r || q<l ) return;
    if( p<=l && q>=r ){
        Cover[n]++;
        Node[n] = r-l+1;
        return;
    }
    if( l==r ) return;
    long m = (l+r)/2;
    Update( 2*n,l,m,p,q );
    Update( 2*n+1,m+1,r,p,q );
    if( !Cover[n] ) Node[n] = Node[2*n]+Node[2*n+1];
}

void Delete( long n,long l,long r,long p,long q )
{
    if( p>r || q<l ) return;
    if( p<=l && q>=r ){
        Cover[n]--;
        if( !Cover[n] ) Node[n] = Node[2*n]+Node[2*n+1];;
        return;
    }
    if( l==r ) return;
    long m = (l+r)/2;
    Delete( 2*n,l,m,p,q );
    Delete( 2*n+1,m+1,r,p,q );
    if( !Cover[n] ) Node[n] = Node[2*n]+Node[2*n+1];
}

int main( void )
{
    long i,j,x1,y1,x2,y2,x3,y3,x4,y4;

    //freopen("text1.txt","r",stdin );
    while(1){
        scanf("%ld",&N );
        if( !N) break;
        for( i=1;i<=N;i++){
            scanf("%ld%ld%ld%ld%ld%ld%ld%ld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4 );
            v[x1].pb( LINE( y1+1,y2,true));
            v[x3].pb( LINE( y1+1,y2,false));

            v[x3].pb( LINE( y1+1,y3,true));
            v[x4].pb( LINE( y1+1,y3,false));

            v[x3].pb( LINE( y4+1,y2,true));
            v[x4].pb( LINE( y4+1,y2,false));

            v[x4].pb( LINE( y1+1,y2,true));
            v[x2].pb( LINE( y1+1,y2,false));
        }

        memset( Node,0,sizeof(Node));
        memset( Cover,0,sizeof(Cover));
        long Ans = 0;
        for( i=0;i<=MAX;i++){
            for( j=0;j<v[i].size();j++){
                if( v[i][j].y1 > v[i][j].y2 ) continue;
                if( v[i][j].IsLeft ) Update( 1,1,MAX,v[i][j].y1,v[i][j].y2 );
                else Delete( 1,1,MAX,v[i][j].y1,v[i][j].y2 );
            }
            Ans += Node[1];
            v[i].clear();
        }
        cout<<Ans<<endl;
    }

    return 0;
}
