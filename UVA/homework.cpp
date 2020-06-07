#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int a,b,l,c,count=0,d;
    char equal,sign,ch[500];
    while(scanf("%d%c%d%c%s",&a,&sign,&b,&equal,&ch)==5)
    {
        l=strlen(ch);
        ch[l]='\0';
        if(isdigit(ch[0]))
        {
            c=0;
            for(int i=0;ch[i]!='\0';i++)
            {
                c=(c*10)+(ch[i]-'0');
            }
            //printf("%d",c);

                if(sign=='+'){d=a+b;}
             else if(sign=='-'){d=a-b;}
             //printf(" d=%d\n",d);
         if(c==d)count++;
        }
        ch[0]='\0';
    }
    printf("%d\n",count);
    return 0;
}
