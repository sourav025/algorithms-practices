/// TLE 


#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <utility>
#include<stdlib.h>
using namespace std;

#define miN(a,b) ( ((a)<(b))?(a):(b) )
#define maX(a,b) ( ((a)>(b))?(a):(b) )

struct Point
{
    int first,second;
    Point(int f=0,int l=0)
    {
        first=f,second=l;
    }
}tree[3*30009];

int x[300009],n;
void buildTree(int node, int a, int b)
{
    if(a>b) return ;
    if(a==b)
    {
        tree[node]=Point(x[a],a);
        return ;
    }
    int mid=((a+b)>>1);
    buildTree((node<<1),a,mid);
    buildTree(((node<<1)|1),mid+1,b);


    if( tree[(node<<1)].first < tree[((node<<1)|1)].first || (tree[(node<<1)].first == tree[((node<<1)|1)].first
            && tree[(node<<1)].second < tree[((node<<1)|1)].second)   )

        tree[node]=tree[(node<<1)];
    else tree[node]=tree[(node<<1)|1] ;
}

Point Rmq(int R, int a,int b, int p, int q)
{
    //printf("R=%d a=%d b=%d p=%d q=%d\n",R,a,b,p,q);
    int mid;
    Point left,right;

    if(p<=a&&b<=q)
        return tree[R];

    mid = (a+b)>>1;

    if(mid<p) return Rmq( ((R<<1)|1) , mid+1,b,p,q);
    if(mid>=q) return Rmq( (R<<1) , a,mid,p,q);

    left = Rmq((R<<1), a,mid,p,q);
    right = Rmq(((R<<1)|1), mid+1,b,p,q);

    Point rt=((left.first<right.first) ? (left)
                      :((left.first==right.first&&left.second<right.second)?(left):(right)));

    return rt;
}

int back(int l,int r)
{
    if(l==r) return x[l];
    if(l>r) return -1;

    Point mp=Rmq(1,0,n-1,l,r);

    int pv=mp.second;
    int mv=mp.first*(r-l+1) ;

    return maX(mv, maX(back(l,pv-1) , back(pv+1,r)));
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&x[i]);
        buildTree(1,0,n-1);
        int res=back( 0,n-1);
        printf("Case %d: %d\n",cas,res);
    }
    return 0;
}
