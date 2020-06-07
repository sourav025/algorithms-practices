#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
using namespace std;
char ch[100][100],st[10]={'@','I','E','H','O','V','A','#','\0'};
int n,m,k=0;
void reset()
{
    for(int i=0;i<=n;i++)
    {
        memset(ch[i],'\0',m+1);
    }
    k=0;
}
void fill(int a,int b)
{
    if(a>=0&&a<n && b>=0&&b<m && ch[a][b]&&k<7&& st[k])
    {
        //puts("2 called fill");
        if(k!=0)printf(" ");
        if(ch[a-1][b]==st[k+1])
        {
            printf("forth");
            k++;
            fill(a-1,b);
        }
        else if(ch[a][b-1]==st[k+1])
        {
            printf("left");
            k++;
            fill(a,b-1);
        }
        else if(ch[a][b+1]==st[k+1])
        {
            printf("right");
            k++;
            fill(a,b+1);
        }
    }
}
int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        getchar();
        for(i=0;i<n;i++)
        {
            gets(ch[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ch[i][j]=='@')
                {
                    fill(i,j);
                    break;
                }
            }
        }
        printf("\n");
        reset();
    }
    return 0;
}
