#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

#define inf 2147483647

int area;

int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int maxx=-1,maxy=-1,maxz=-1,minx=inf,miny=inf,minz=inf;
//        cout<<minx;
        int n;cin>>n;
        while(n--)
        {
            int x,y,z;
            cin>>x>>y>>z;
            maxx=max(maxx,x);
            maxy=max(maxy,y);
            maxz=max(maxz,z);

            cin>>x>>y>>z;
            minx=min(minx,x);
            miny=min(miny,y);
            minz=min(minz,z);
        }
        area=1;
        area=max(0,minx-maxx) * max(0,miny-maxy) * max(0,minz-maxz);

        cout<<"Case "<<cas<<": "<<area<<endl;

    }
    return 0;
}
