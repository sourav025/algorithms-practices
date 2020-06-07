#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    map<string,int>mp;
    map<string,int>::iterator it;
    string str;
    char nam[100];
    scanf("%d",&n);j=0;
        for(i=0;i<n;i++)
        {
            cin>>str;
            getchar();
            gets(nam);
            mp[str]=mp[str]+1;
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            cout<<(*it).first<<" "<<(*it).second<<endl;
        }
    return 0;
}
