#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct Node{
    int num;
    int div;
    Node(int a=0,int b=0)
    {
        num=a,div=b;
    }
}ar[1002];

bool cmp(const Node &a,const Node &b){
    if(a.div!=b.div)
        return a.div<b.div;
    return a.num>b.num;
}

void pre()
{
    ar[0].num=0,ar[0].div=0;
    ar[1].num=1,ar[1].div=1;
    ar[2].num=2,ar[2].div=2;
    ar[3].num=3,ar[3].div=2;
    for(int n=4;n<1001;n++)
    {
        ar[n].div=1;int dhor=n;
        ar[n].num=n;
        for(int i=2;i*i<=dhor;i++)
        {
            int cnt=0;
            while(dhor%i==0&&dhor>1)
            {
                cnt++;dhor/=i;
            }
            ar[n].div*=(cnt+1);
        }
        if(dhor>1)
            ar[n].div*=2;
    }
    sort(ar,ar+1001,cmp);
}

int main()
{
    pre();
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",cas,ar[n].num);
    }
    return 0;
}
