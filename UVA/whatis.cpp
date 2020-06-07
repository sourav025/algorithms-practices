#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<stdlib.h>
using namespace std;
char ch[1000000];
int main()
{
    int i,j,k,l,max;
    while(gets(ch)&&ch[0]!='\0')
    {
        map<char,int>mp;
    map<char,int>::iterator it;
        max=0;
        for(i=0;i<strlen(ch);i++)
        {

            if(isalpha(ch[i])!=0){
            mp[ch[i]]=mp[ch[i]]+1;
            if(max<(mp[ch[i]])){max=mp[ch[i]];}}
            //cout<<ch[i]<<" ";
        }
        for(it=mp.begin();it!=mp.end();it++)
        {
            if((*it).second==max){cout<<(*it).first;}
        }
        cout<<" "<<max<<endl;
    }
    return 0;
}

