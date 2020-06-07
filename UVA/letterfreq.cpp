#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int i,j,t,cas,k;
    char ch[2000],m,n;
    scanf("%d",&t);
    getchar();
    for(cas=0;cas<t;cas++){
        k=0;
    gets(ch);
    for(i=0;i<strlen(ch);i++)
    {
        int count=0;
        if(isalpha(ch[i])!=0)
           {
               for(j=i+1;j<strlen(ch);j++)
               {
                   if(ch[j]==ch[i]&&ch[j+1]==ch[i+1])
                   count++;
               }
               if(count>k){k=count;m=ch[i];n=ch[i+1];}
           }
    }
    printf("%c%c\n",m,n);}
    return 0;
}
