#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back

bool cmp(const int &a,const int& b)
{
    return a>b;
}

int ar[15];

int main()
{
    int des,n,sum;
    set<string> res;
    while(scanf("%d%d",&des,&n)==2&&des&&n)
    {

        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        sort(ar,ar+n,cmp);

        for(int i=0;i<(1<<n);i++)
        {
            sum=0;
            string str="";
            for(int mask=0;mask<n;mask++)
            {
                if(i&(1<<mask))
                {
                    char s[20];
                    sprintf(s,"%d",ar[mask]);

                    if(sum==0) str+=s;
                    else str+="+",str+=s;

                    sum+=ar[mask];
                }
            }
            if(sum==des)
                res.insert(str);
        }
        cout<<"Sums of "<<des<<":"<<endl;
        if(res.size()>0)
        for(set<string>::reverse_iterator it=res.rbegin();it!=res.rend();it++)
        {
            cout<<(*it)<<endl;
        }
        else printf("NONE\n");
        res.clear();
    }
    return 0;
}
