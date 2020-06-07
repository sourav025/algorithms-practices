#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    //freopen("dela.txt","r",stdin);
    map<string,string>mp;
    int x,y,i,j,k,l,n;
    string s1,s2;
    char ch[5000];
    scanf("%d%d",&l,&n);
    for(i=0;i<l;i++)
    {
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    for(i=0;i<n;i++)
    {
        scanf("%s",&ch);
        if(mp[ch]!="\0")
        {
            cout<<mp[ch]<<endl;
        }
        else
        {
            k=strlen(ch);
            if(ch[k-1]=='o'||ch[k-1]=='s'||(ch[k-1]=='h'&&ch[k-2]=='c')
               ||ch[k-1]=='x'||(ch[k-1]=='h'||ch[k-2]=='s'))
            {
                cout<<ch<<"es"<<endl;
            }
            else if(ch[k-1]=='y'&&(ch[k-2]!='a'&&ch[k-2]!='e'&&ch[k-2]!='i'
                                   &&ch[k-2]!='o'&&ch[k-2]!='u'))
            {
                ch[k-1]='i';
                ch[k++]='e';
                ch[k++]='s';
                ch[k]='\0';
                cout<<ch<<endl;
            }
            else cout<<ch<<"s"<<endl;
        }
    }
    return 0;
}
