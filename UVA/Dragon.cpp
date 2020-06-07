#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long h[20009]={0},ar[20009]={0};
int main()
{
    long long i,j,k,l,n,m,res,cnt;
    while(cin>>n>>m&&(n>0||m>0))
    {
        for(i=0;i<n;i++)
        cin>>h[i];
        sort(h,h+n);
        for(i=0;i<m;i++)
        cin>>ar[i];
        sort(ar,ar+m);
        res=0;
        cnt=0;
        l=0;
        for(i=0;i<n;i++)
        {
            for(j=l;j<m;j++)
            {
                if(h[i]<=ar[j])
                {
                    cnt++;
                    res+=ar[j];
                    l=j+1;
                    break;
                }
            }
            h[i]=0;
        }
        if(cnt==n)
        cout<<res<<endl;
        else printf("Loowater is doomed!\n");
        for(i=0;i<=m;i++)
        ar[i]=0;
    }
    return 0;
}
