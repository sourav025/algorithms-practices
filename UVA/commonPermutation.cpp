#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
char ch1[100000],ch2[100000],res[100000];
int main()
{
    int i,j,k,l1,l2;
    while(gets(ch1)&&gets(ch2))
    {
        k=0;
        l1=strlen(ch1);
        l2=strlen(ch2);
        for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                if(ch1[i]==ch2[j])
                {
                    res[k++]=ch1[i];
                    ch1[i]='\0';
                    ch2[j]='\0';
                    break;
                }
            }
        }
        res[k]='\0';
        sort(res,res+k);
        puts(res);
        memset(ch1,'\0',l1+2);
        memset(ch2,'\0',l2+2);
        memset(res,'\0',k+3);
    }
    return 0;
}
