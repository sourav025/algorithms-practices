#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

int ans = 1;

struct Node
{
    bool endm;
    Node *next[10];
    Node()
    {
        endm=false;
        for(int i=0;i<10;i++)
            next[i]=NULL;
    }
}*root;

void ins(char *str, int len)
{
    Node *cur=root;
    bool created = false;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        if(cur->next[id]==NULL){
            cur->next[id]=new Node();
            if(cur->endm) ans = 0;
            created = true;
        }
        cur=cur->next[id];
    }
    if(!created) ans = 0;
    cur->endm=1;
}

int searc(char *str,int len)
{
    Node *cur=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        if(cur->next[id]==NULL)
            return false;
        cur=cur->next[id];
    }
    return cur->endm;
}

void del(Node *cur)
{
    for(int i=0;i<10;i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete cur;
}

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        root = new Node();
        int N;
        cin>>N;
        ans = 1;

        while(N--){
            char str[15];
            cin>>str;
            if(ans)
                ins( str, strlen(str) );
        }
        cout<<"Case "<<i<<": ";
        ans? cout<<"YES"<<endl:cout<<"NO"<<endl;

        del(root);
    }
    return 0;
}
