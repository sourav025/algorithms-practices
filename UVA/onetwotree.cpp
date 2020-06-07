#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
char p[4][6]={"one","two","three"};
int main()
{
    int n,i,j,k,m,count,l,flag;
    char ch[10];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(ch);
        l=strlen(ch);
        if(l==5)printf("3\n");
        else if(l==3)
        {
            count=0;
            for(j=0;j<3;j++)
            {
                if(ch[j]==p[0][j])count++;
            }
            if(count>=2)printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
