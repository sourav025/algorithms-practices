#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char ch[100000000],res[100000000];
int check()
{
    long long i;
    for(i=0;i<strlen(res)/2;i++)
    {
        if(res[i]!=res[strlen(res)-1-i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    long long r,i,j,k,l;
    while(gets(ch))
    {
        i=0,j=0;
        while(ch[i])
        {
            if(isalpha(ch[i]))
            {
                res[j++]=tolower(ch[i]);
            }
            i++;
        }
        res[j]='\0';
        if(strcmp(res,"done")==0)break;
        //printf("%s\n",res);
        r=check();
        if(r==1)printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}
