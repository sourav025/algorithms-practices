#include<stdio.h>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;

map<int,int> mp;
int ar[20],lf,rt;

void setMap()
{
    int len=pow(3.0,lf);
    for(int i=0;i<len;i++)
    {
        int sum=0,store=i;
        for(int j=0;j<lf;j++)
        {
            sum+=(store%3)*ar[j]; store/=3;
        }
        mp[sum]=1;
    }
}

bool search(int des)
{
    int len=pow(3.0,rt);
    for(int i=0;i<len;i++)
    {
        int sum=0,store=i;
        for(int j=0;j<rt;j++)
            sum+=(store%3)*ar[lf+j], store/=3;
        if(mp[des-sum])
            return 1;
    }
    return 0;
}

int main()
{
    int t,k,n;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        mp.clear();
        scanf("%d%d",&n,&k);
        lf=(n>>1);
        rt=n-lf;
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        setMap();

//        Showing the half all combinations
//        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
//        {
//            cout<<(*it).first<<" ";
//        }
//        cout<<endl;
        cout<<"Case "<<cas;
        search(k)?cout<<": Yes\n":cout<<": No\n";
    }
    return 0;
}

//3
//2 5
//1 2
//2 10
//1 2
//3 10
//1 3 5
