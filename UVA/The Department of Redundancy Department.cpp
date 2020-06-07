#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>

using namespace std;

vector<int> seq;
map<int,int> mp;

int main()
{
    int num;
    char c;
    while(scanf("%d%c",&num,&c)==2)
    {
        if(mp[num]==0) mp[num]=1,seq.push_back(num);
        else mp[num]++;
        if(c=='\n') break;
    }
    for(int i=0;i<seq.size();i++)
    {
        num=seq[i];
        cout<<num<<" "<<mp[num]<<endl;
    }
    return 0;
}
