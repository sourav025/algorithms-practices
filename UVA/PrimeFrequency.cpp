#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<vector>
#include<ctype.h>
using namespace std;

bool prime[2006];

void pre()
{
    prime[0]=1,prime[1]=1;
    for(int i=2;i*i<=2005;i++)
        for(int j=i+i;j<2005;j+=i)
            prime[j]=1;
}

char ch[2050];

int main()
{
    pre();
    map<char,int>mp;
    map<char,int>::iterator it;
    int t;scanf("%d",&t);getchar();
    for(int cas=1;cas<=t;cas++)
    {
        char c;scanf("%c",&c);
        while(c!='\n')
        {
            mp[c]++; c=getchar();
        }
        bool f=0;
        printf("Case %d: ",cas);
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(!prime[(*it).second])
                {printf("%c",(*it).first);f=1;}
        }
        if(f) printf("\n");
        else printf("empty\n");
        mp.clear();
    }
    return 0;
}
