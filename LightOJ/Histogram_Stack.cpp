#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int ind,hi;
};

Node s1,s2,s3;
int n,ar[100009];

int  main()
{
    int t;scanf("%d",&t);
    stack<Node> stk;
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);

        s1.ind=0,s1.hi=-1;  stk.push(s1);
        s1.ind=1,s1.hi=ar[1];  stk.push(s1);

        int mx=0,ls;
        for(int i=2;i<=n;i++)
        {
            s1=stk.top(); ls=i;
            if(s1.hi<ar[i])
            {
                s1.hi=ar[i],s1.ind=i;stk.push(s1);
            }
            else if(s1.hi==ar[i])
            {
                continue;
            }
            else {
                while(!stk.empty())
                {
                    s1=stk.top();
                    mx=max(mx, ((i-s1.ind)*(s1.hi) ));
                    if(s1.hi < ar[i])
                    {
                        s1.hi=ar[i],s1.ind=ls;stk.push(s1);
                        break;
                    }
                    else if(s1.hi == ar[i])
                    {
                        break;
                    }
                    else ls=s1.ind;
                    stk.pop();
                }
            }
        }
        while(!stk.empty())
        {
            s1=stk.top();
            mx=max(mx, ((n+1-s1.ind)*(s1.hi) ));
            stk.pop();
        }
        printf("Case %d: %d\n",cas,mx);

    }
    return 0;
}
