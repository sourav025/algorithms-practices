#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define SZ 30
#define pb push_back
using namespace std;


vector<int> getLis(vector<int> &a)
{
   int n = a.size();
   vector<int>b,p; /// p for parent of each no in the LIS , indexes of a in b
   p.resize(n);
   b.pb(0); p[0] = -1;
   int cur = 1;

   while(cur<n) {
       if(a[ b[b.size()-1] ] < a[cur] ) b.pb(cur) , p[cur] = b[b.size()-2];  /// if current no is greater than last no
       else { /// find the highest index where a[b [index] ] < a[cur]
           int  lo , hi, mid, ans = -1;
           lo = 0; hi = b.size()-1;
           while(lo<=hi) {
               mid = (lo+hi)/2;
               if(a[ b[ mid ] ] < a[cur] ) ans = mid , lo = mid + 1;
               else hi = mid - 1;
           }
           if(ans==-1) b[0] = cur , p[cur] = -1; /// if not found that means this is the smallest no, so insert it first
           else b[ans+1] = cur , p[cur] = b[ans];
       }
       cur++;
   }

   vector<int> ret;
   cur = b[b.size()-1];
   while(cur!=-1) {
       ret.pb(a[cur]);
       cur = p[cur];
   }
   reverse(ret.begin(),ret.end());
   return ret;
}


int num[40],val[40];

int main()
{
    int n,v;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++) scanf("%d",&v),val[v]=i;

    for(int i=1;i<n+1;i++) num[val[i]]=i;

    vector<int> vec;

    while(scanf("%d",&v)==1)
    {
        val[v]=1;

        for(int i=2;i<=n;i++){
            scanf("%d",&v);val[v]=i;
        }

        vector<int> vec;

        for(int i=1;i<n+1;i++)
            vec.push_back(num[val[i]]);

        vector<int> ans=getLis(vec);
        printf("%d\n",ans.size());
        vec.clear();
    }

    return 0;
}
