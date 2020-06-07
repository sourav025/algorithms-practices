#include<stdio.h>
#include<string.h>

#define MIN(a,b) ((a<b)?(a):(b))

int main()
{
    int n;
    char ch;
    while(scanf("%d",&n)==1&&n)
    {
        getchar();
        char cur='\0';

        int st=-1;

        int res=n+10;

        bool both=false;

        for(int i=0;i<n;i++)
        {
            scanf("%c",&ch);
            if(ch=='.' || both) continue;
            if(ch=='z'||ch=='Z') {both=true;res=0;continue;}

            if(cur=='\0'){
                cur=ch,st=i;
                continue;
            }

            if(ch==cur)
                st=i;
            else
            {
                res=MIN(res,i-st);
                cur=ch;
                st=i;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
/*
10
.R..Z...D.
/*
