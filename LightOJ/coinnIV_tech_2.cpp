#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec[2];
int ar[20],lf,rt;

void setMap(int id,int ln,int ad)
{
    int len=pow(3.0,ln);
    for(int i=0;i<len;i++)
    {
        int sum=0,store=i;
        for(int j=0;j<ln;j++)
        {
            sum+=(store%3)*ar[ad+j]; store/=3;
        }
        vec[id].push_back(sum);
    }
    sort(vec[id].begin(),vec[id].end());
}

bool search(int des)
{
    int i=0,len=vec[0].size();
    int j=vec[1].size()-1;
    while(i<len&&j>=0)
    {
        int sm=vec[0][i]-des+vec[1][j];
        while(i+1<len&&vec[0][i]==vec[0][i+1]) i++;
        while(j>0&&vec[1][j]==vec[1][j-1]) j--;

        if(sm==0) return 1;
        if(sm<0) i++;
        if(sm>0) j--;
    }
    return 0;
}

int main()
{
    int t,k,n;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        vec[0].clear(),vec[1].clear();
        scanf("%d%d",&n,&k);
        lf=(n>>1);
        rt=n-lf;
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        setMap(0,lf,0);
        setMap(1,rt,lf);
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
