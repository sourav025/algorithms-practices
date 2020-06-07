#include<stdio.h>
#include<string.h>
int main()
{
    char msg[5000];
    int i,j,k,n,count;
    scanf("%d",&n);
    getchar();
    for(k=1;k<=n;k++)
    {
        count=0;
        gets(msg);
        for(i=0;i<strlen(msg);i+=1)
        {
            if(msg[i]=='a'||msg[i]=='d'||msg[i]=='g'||msg[i]=='j'
               ||msg[i]=='m'||msg[i]=='p'||msg[i]=='t'||msg[i]=='w'||msg[i]==' ')
               {
                   count+=1;
               }
            else if(msg[i]=='b'||msg[i]=='e'||msg[i]=='h'||msg[i]=='k'
               ||msg[i]=='n'||msg[i]=='q'||msg[i]=='u'||msg[i]=='x')
               {
                   count+=2;
               }
            else if(msg[i]=='c'||msg[i]=='f'||msg[i]=='i'||msg[i]=='l'
               ||msg[i]=='o'||msg[i]=='r'||msg[i]=='v'||msg[i]=='y')
               {
                   count+=3;
               }
               else if(msg[i]=='s'||msg[i]=='z')
               {
                   count+=4;
               }
        }
        printf("Case #%d: %d\n",k,count);
    }
    return 0;
}
