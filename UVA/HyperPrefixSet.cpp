#include<stdio.h>
#include<string.h>


#define Max(a,b) ((a>b)?(a):(b))

struct Node{
    int len,cnt;
    Node *next[2];
    Node()
    {
        len=0,cnt=0;
        for(int i=0;i<2;i++)
            next[i]=NULL;
    }
}*root;

int ans;

void insert(char *ch,int len)
{
    Node *cur=root;
    for(int i=0;i<len;i++)
    {
        int id=ch[i]-'0';

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
    for(int i=0;i<2;i++)
    {
        if(cur->next[i]!=NULL)
        {
            ans=Max(ans,(cur->next[i]->cnt*cur->next[i]->len));
            del(cur->next[i]);
        }
    }
    delete cur;
}

char ch[205];

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
        printf("%d\n",ans);
    }
    return 0;
}

/*
4
4
0000
0001
10101
010
2
01010010101010101010
11010010101010101010
3
010101010101000010001010
010101010101000010001000
010101010101000010001010
5
01010101010100001010010010100101
01010101010100001010011010101010
00001010101010110101
0001010101011010101
00010101010101001
*/

