#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,a,t,b,l,k,c,d,cas;
    char ch1[250],ch2[250];
    scanf("%d",&t);
    for(cas=0;cas<t;cas++)
    {char ans[300]={"0"};
    scanf("%s%s",&ch1,&ch2);
        int r=0,e=0;
        l=strlen(ch1);
        k=strlen(ch2);
        d=l;
        if(k>l)d=k;
        for(i=0;i<d;i++)
        {
            if(ch1[i]&&i<l)a=(ch1[i]-'0');
            else a=0;
            if(ch2[i]&&i<k)b=(ch2[i]-'0');
            else b=0;
            c=a+b+r;
            r=0;
            if(c>9)
            {r=c/10;c%=10;}
            if(c==0)
            {
                if(ans[0]!='0'){
                ans[e++]=(c+'0');}
            }
            else if(c!=0)ans[e++]=(c+'0');
        }
        if(r!=0){
        ans[e++]=r+'0';}
        //ans[e]='\0';
        //printf("e=%d ",e);
        if(e==0){
        printf("0\n");}
        else
        printf("%s\n",ans);
    }
    return 0;
}
