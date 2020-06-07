#include<stdio.h>
#include<math.h>
#include<map>
#include<iostream>
using namespace std;

typedef long long Long;
map<Long,int> mp;

int si[109];

int main()
{
    int n,d,t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>n>>d;
        mp.clear();
        for(int i=0;i<n;i++) cin>>si[i];
        Long rech=(n*n*10000)+(d*d);
        int min=-1;
        for(int i=0;i<n;i++)
        {
            Long sum=ar[i];
            if(rech%sum==0)
            {

            }
        }
    }
    return 0;
}
