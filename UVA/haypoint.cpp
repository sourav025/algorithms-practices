#include<stdio.h>
#include<map>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
    int i,j,k,a,n,t,cas;
    char ch[1000],line[1000];
    string str;
    map<string,int>mp;
    map<string,int>::iterator it;
    scanf("%d%d",&k,&t);getchar();
    for(cas=1;cas<=k;cas++)
    {
        cin>>str>>a;
        mp[str]=a;getchar();
    }
    for(cas=1;cas<=t;cas++)
    {
        int sum=0;
        while(gets(line)&&line[0]!='.')
        {
            int k=0,l,m=0;

            for(i=0;i<=strlen(line);i++)
            {
                if(line[i]==' '||line[i]=='\0')
                {
                    l=0;
                    for(j=m;j<i;j++)
                    {
                        ch[l++]=line[j];
                    }
                    ch[l]='\0';
                    if(mp[ch]!=0){sum+=mp[ch];}
                    m=i+1;k+=1;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
