#include<stdio.h>
#include<string.h>

int main()
{
    int base,mod;
    char ch[1000],k[12];
    while(scanf("%d",&base)==1&&base)
    {
        scanf("%s%s",&ch,&k);
        int sum=0,ex=1;
        mod=0;
        for(int i=strlen(k)-1;i>=0;i--)
        {
            mod+=(k[i]-'0')*ex;
            ex*=base;
        }
        ex=1;
        for(int i=strlen(ch)-1;i>=0;i--)
        {
            sum+=(ch[i]-'0')*ex;
            sum%=mod;
            ex=(ex*base)%mod;
        }

        if(sum==0){
            printf("%lld\n",sum);
        }
        else
        {
            int id=0;
            while(sum)
            {
                ch[id++]=(sum%base)+'0';
                sum/=base;
            }
            for(;id;)
            {
                printf("%c",ch[id-1]);id--;
            }
            printf("\n");
        }
    }
    return 0;
}

