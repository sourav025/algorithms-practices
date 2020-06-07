#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    long long c,n,i,m,j,k,l;
    char ch[1000000],ch2[3],sign,res[1000000];
    while(scanf("%s%s%lld",&ch,&ch2,&n)==3)
    {
        l=strlen(ch);
        m=0,k=0,c=0;
        if(ch2[0]=='/')sign='/';
        if(ch2[0]=='%')sign='%';
        //printf("sign %d",strlen(ch2));
        j=n;
        while(j>0)
        {
            c++;
            j/=10;
        }
        //printf("size of %d \n",c);
        if(l<c&&sign=='%')
        printf("%s\n",ch);
        else {
        for(i=0;i<strlen(ch);i++)
        {
            m=(m*10)+(ch[i]-'0');
            res[k++]=(m/n)+'0';
            m%=n;
        }
        res[k]='\0';
        if(sign=='/')
        {
            if(res[0]=='\0')
            printf("0\n");
            else
            {
                j=0;
                while(res[j]=='0')
                {
                    j++;
                }
                if(res[j]=='\0')
                printf("0");
                while(res[j]!='\0')
                {
                    printf("%c",res[j]);
                    j++;
                }
                printf("\n");
            }
        }
        else if(sign=='%')printf("%d\n",m);}
        sign = '\0';
        memset(ch,'\0',l+2);
        memset(ch2,'\0',3);
    }
    return 0;
}

