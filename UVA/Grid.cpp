#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int k=0,len=0;
char ch[10000][10000],c='\0';
void reset()
{
     int l,i;
     for(i=0;i<=k+1;i++)
     {
         l=strlen(ch[i]);
         memset(ch[i],'\0',l+2);
     }
    len=0;
    k=-1;
}
void fill(int a,int b)
{
    if(a>=0&&a<=k&&b>=0&&b<len&&ch[a][b])
    {
         ch[a][b]=c;
         if(ch[a-1][b]==' ')
         fill(a-1,b);
         if(ch[a][b+1]==' ')
         fill(a,b+1);
         if(ch[a][b-1]==' ')
         fill(a,b-1);
         if(ch[a+1][b]==' ')
         fill(a+1,b);
    }
}
int main()
{
    int i,j,l,n;
    //freopen("text.txt","r",stdin);
    while(gets(ch[k]))
    {
            l=strlen(ch[k]);
            if(l>len) len=l;
        if(ch[k][0]=='_')
        {
            for(i=0;i<k;i++)
            {
                for(j=0;j<strlen(ch[i]);j++)
                {
                    if(ch[i][j]!='X'&&ch[i][j]!=' ')
                    {
                        c=ch[i][j];
                        //printf("ch = %c and called fill with a=%d b=%d\n",c,i,j);
                        fill(i,j);
                    }
                }
            }
            for(i=0;i<=k;i++)
            puts(ch[i]);
            reset();
        }
        k++;
    }
    return 0;
}
