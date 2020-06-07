#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


struct POINT{
	long x,y;
	long I;
	POINT( long x = 0,long y = 0,long I = 0 )
	{
		this->x = x;
		this->y = y;
		this->I = I;
	}
	void scan()
	{
	    scanf("%d%d",&x,&y);
	}
};
bool operator<( const POINT &a,const POINT &b )
{
	if( a.x != b.x ) return a.x < b.x;
	else return a.y < b.y;
}

long N;
vector<POINT> Pt;
vector<bool> Del;

long S(long x) {return x*x;}

long Area2( POINT a,POINT b,POINT c )
{
	return a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - c.x*b.y;
}

long dist(POINT &A,POINT &B)
{
    return (S(A.x-B.x)+S(A.y-B.y));
}


bool Cmp( const POINT &a,const POINT &b )
{
	long Ar = Area2( Pt[0],a,b );
	if( Ar ) return Ar>0;
	long Dx = labs( Pt[0].x-a.x ) - labs( Pt[0].x-b.x );
	long Dy = labs( Pt[0].y-a.y ) - labs( Pt[0].y-b.y );
	if( Dx<0 || Dy<0 ){
		Del[a.I] = true;
		return true;
	}
	else if( Dx>0 || Dy>0 ){
		Del[b.I] = true;
		return false;
	}
	return true;
}

void Squash( void )
{
	long i,j;
	for( i=j=0;i<N;i++){
		if( Del[Pt[i].I] ) continue;
		Pt[j] = Pt[i];
		j++;
	}
	Pt.resize( j );
	N = j;
}
void ConvexHull( vector<POINT> &Hull )
{
	sort( Pt.begin(),Pt.end()); /// Pt[0] wiil contain leftmst-lowest point
	sort( Pt.begin()+1,Pt.end(),Cmp );
	Squash();
	if( Pt.size()>=1 ) Hull.push_back( Pt[0] );
	if( Pt.size()>=2 ) Hull.push_back( Pt[1] );
	long i = 2;
	while( i<N ){
		long s = Hull.size();
		if( Area2( Hull[s-2],Hull[s-1],Pt[i] )>0 ){
			Hull.push_back( Pt[i] );
			i++;
		}
		else Hull.pop_back();
	}
}

bool isSquare(POINT A,POINT B,POINT C,POINT D)
{
    long a=dist(A,B);
    long b=dist(B,C);
    long c=dist(C,D);
    long d=dist(D,A);

    long k1=dist(A,C);
    long k2=dist(B,D);

    return (a==b&& b==c && c==d && a==d && k1==k2);
}

bool isRhombus(POINT A,POINT B,POINT C,POINT D)
{
    long a=dist(A,B);
    long b=dist(B,C);
    long c=dist(C,D);
    long d=dist(D,A);

    long k1=dist(A,C);
    long k2=dist(B,D);

    return (a==b&& b==c && c==d && a==d && k1!=k2);
}

bool isRectangle(POINT A,POINT B,POINT C,POINT D)
{
    long a=dist(A,B);
    long b=dist(B,C);
    long c=dist(C,D);
    long d=dist(D,A);

    long k1=dist(A,C);
    long k2=dist(B,D);

    return (a==c&& b==d && k1==k2);
}

bool isParalellogram(POINT A,POINT B,POINT C,POINT D)
{
    long a=dist(A,B);
    long b=dist(B,C);
    long c=dist(C,D);
    long d=dist(D,A);

    long k1=dist(A,C);
    long k2=dist(B,D);

    return (a==c&& b==d && k1!= k2);
}

bool isTrapizium(POINT A,POINT B,POINT C,POINT D)
{
    long long p = (A.y - B.y) * (C.x - D.x);
    long long q = (A.x - B.x) * (C.y - D.y);
    long long r = (B.y - C.y) * (A.x - D.x);
    long long s = (B.x - C.x) * (A.y - D.y);

    return (p==q || r==s);
}

void solveAndOutput(vector<POINT> &Hull)
{
    if(isSquare(Hull[0],Hull[1],Hull[2],Hull[3])) printf("Square\n");
    else if(isRhombus(Hull[0],Hull[1],Hull[2],Hull[3])) printf("Rhombus\n");
    else if(isRectangle(Hull[0],Hull[1],Hull[2],Hull[3])) printf("Rectangle\n");
    else if(isParalellogram(Hull[0],Hull[1],Hull[2],Hull[3])) printf("Parallelogram\n");
    else if(isTrapizium(Hull[0],Hull[1],Hull[2],Hull[3])) printf("Trapezium\n");
    else printf("Ordinary Quadrilateral\n");
}

int main( void )
{
//    freopen("in.txt","r",stdin);

    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        N=4;
        Pt.resize(N); // repeated point is needed to omit by set
        Del.resize(N);

        for(int i=0;i<N;i++)
        {
            POINT p0;
            p0.scan();
            Pt[i]=p0;
        }
        printf("Case %d: ",cas);

        vector<POINT> Hull;
        ConvexHull( Hull );

        if(Hull.size()<4)
        {
            printf("Ordinary Quadrilateral\n");
            continue;
        }


        solveAndOutput(Hull);

        Hull.clear();
        Pt.clear();
        Del.clear();
    }
	return 0;
}
/*

6
0 0
2 0
2 2
0 2
0 0
3 0
3 2
0 2
0 0
8 4
5 0
3 4
0 0
2 0
3 2
1 2
0 0
5 0
4 3
1 3
0 0
5 0
4 3
1 4

*/
