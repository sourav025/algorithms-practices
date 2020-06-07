#include<stdio.h>
#include<string.h>

int tree[100010],len;

int read(int idx)
{
	int sum = 0;
	while (idx > 0)
    {
		sum ^= tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val)
{
	while (idx <= len)
    {
		tree[idx] ^= val;
		idx += (idx & -idx);
	}
}

char ch[100009];

int main()
{
    int t,q,l1,l2,qr;
    char cc[4];
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(ch,0,sizeof(ch));
        memset(tree,0,sizeof(tree));
        getchar();
        gets(ch+1);

        len=strlen(ch+1);

        for(int i=1;i<=len;i++)
        {
            if(ch[i]=='1'){
                update(i,1);
                update(i+1,1);
            }
        }

        scanf("%d",&q);

        printf("Case %d:\n",cas);

        while(q--)
        {
            scanf("%s",cc+1);
            if(cc[1]=='Q')
            {
                scanf("%d",&qr);

                int rr=read(qr);
                printf("%d\n",rr);
            }
            else if(cc[1]=='I')
            {
                scanf("%d%d",&l1,&l2);
                update(l1,1);
                update(l2+1,1);
            }
            cc[1]='\0';
        }
    }
    return 0;
}

/*

2
0011001100
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
1011110111
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5

*/
