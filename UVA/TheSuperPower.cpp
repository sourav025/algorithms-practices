#include<stdio.h>
#include<math.h>
#include<string.h>
#include<set>
#include<iostream>
using namespace std;

#define eps 1e-9

typedef unsigned long long ull;

ull power(ull n,int p)
{
    if(p==0) return 1LL;

    if(p&1LL)
        return power(n,p-1)*n;

    ull nx=power(n,p/2);
    return (nx*nx);
}

int main()
{

//    freopen("C:/Users/sourav.sarker/Desktop/Bootstrap/out.txt","wt",stdout);

    bool nPm[100]={};
    for(int i=2;i*i<100;i++)
    {
        for(int j=i+i;j<100;j+=i)
        {
            nPm[j]=true;
        }
    }

    int pow[100]={},l=0;
    for(int i=4;i<100;i++)
    {
        if(nPm[i])
        {
            pow[l++]=i;
        }
    }

    set<ull> res;

    res.insert(1LL);

    for(int i=2;i<(1<<16);i++)
    {
        double lim=64.0/( log(i) / log(2) );
        for(int j=0;pow[j]<lim;j++)
            res.insert( power(i,pow[j]) );
    }

    for(set<ull>::iterator it=res.begin();it!=res.end();it++)
        cout<<((*it))<<endl;

    return 0;
}

