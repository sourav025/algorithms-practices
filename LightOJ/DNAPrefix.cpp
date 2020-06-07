#include<stdio.h>
#include<string.h>


#define Max(a,b) ((a>b)?(a):(b))

struct Node{
    int len,cnt;
    Node *next[4];
    Node()
    {
        len=0,cnt=0;
        for(int i=0;i<4;i++)
            next[i]=NULL;
    }
}*root;

int ans;

void insert(char *ch,int len)
{
    Node *cur=root;
    for(int i=0;i<len;i++)
    {
        int id;
        if(ch[i]=='A') id=0;
        else if(ch[i]=='C') id=1;
        else if(ch[i]=='G') id=2;
        else if(ch[i]=='T') id=3;

        if(cur->next[id]==NULL)
        {
            cur->next[id]=new Node();
            cur->next[id]->len=cur->len+1;
        }

        cur=cur->next[id];
        cur->cnt++;
    }
}

void del(Node *cur)
{
    for(int i=0;i<4;i++)
    {
        if(cur->next[i]!=NULL)
        {
            ans=Max(ans,(cur->next[i]->cnt*cur->next[i]->len));
            del(cur->next[i]);
        }
    }
    delete cur;
}

char ch[55];

int main()
{
    int t;scanf("%d",&t);

    for(int cas=1;cas<=t;cas++)
    {
        root=new Node();
        int n;ans=root->cnt;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",&ch);
            insert(ch,strlen(ch));
        }
        del(root);
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}

/*
3
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT
*/
