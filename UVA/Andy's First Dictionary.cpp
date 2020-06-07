#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
char word[10000000],key[5009];
int main()
{
    //freopen("Andy.txt","r",stdin);
    map<string,int>mp;
    map<string,int>::iterator it;
    int i,j,k,l;
    while(gets(word))
    {
        l=strlen(word);
        j=0;
        for(i=0;i<l;i++)
        {
            if(isalpha(word[i])!=0)
            {
                key[j++]=tolower(word[i]);
            }

            if(isalpha(word[i])==0)
            {
                key[j]='\0';
                mp[key]=1;
                memset(key,'\0',j+2);
                j=0;
            }
        }
        key[j]='\0';
        mp[key]=1;
        memset(key,'\0',j+2);
        memset(word,'\0',l+2);
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        if((*it).first!="")
        cout<<(*it).first<<endl;
    }
    return 0;
}
