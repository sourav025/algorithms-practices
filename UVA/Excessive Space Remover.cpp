#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char ch[100000000];
int main()
{
    long long i,j,max=0,k,l,c,cnt;
    while(gets(ch))
    {
        c=0;
        for(i=0;i<strlen(ch);i++)
        {
            cnt=0;
            while(ch[i]==' ')
            {
                cnt++;
                i++;
            }
            if(cnt>max) max=cnt;
        }
        //printf("max %d res ",max);
        while(max>1)
        {
            c++;
            if(max%2==0) max/=2;
            else
            {
                max/=2;
                max++;
            }
        }
        printf("%lld\n",c);
    }
    return 0;
}
