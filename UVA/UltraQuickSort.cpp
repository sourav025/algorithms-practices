#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define MX 500009
#define ll long long

ll tree[MX+7],ar[MX+7],br[MX+7],n;

ll query(ll idx);

void update(ll idx, int x);

int main() {
    
    while(scanf("%lld",&n)==1 && n)
    {
        memset(tree, 0, sizeof(tree));
        for(int i=0;i<n;i++)
            cin>>ar[i], br[i] = ar[i];
        sort(br, br+n);
        for(int i=0;i<n;i++){
            int idx = (int) (lower_bound(br, br+n, ar[i])- br);
            ar[i] = idx+1;
        }
        ll sm = 0;
        for(ll i=n-1;i>=0;i--)
        {
            sm += query(ar[i]-1);
            update(ar[i], 1);
        }
        cout<<sm<<endl;
    }
    
    return 0;
}

ll query(ll idx)
{
    ll sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx -=  (idx&-idx);
    }
    return sum;
}

void update(ll idx, int x)
{
    while(idx<=n+1)
    {
        tree[idx]+=x;
        idx += idx & (-idx);
    }
}