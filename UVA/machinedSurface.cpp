#include<stdio.h>
int main()
{
unsigned int n,i,i1;
while(scanf("%d",&n)==1&&n)
{
    char chr;
    int spaces[30000],min=32767,tsp=0;
    for(i=0;i<30000;i++) spaces[i]=0;
    for(i=0;i<n;i++)
        {
            for(i1=0;i1<26;i1++)
            {scanf("%c",&chr);
            if(chr==' ') spaces[i]++;}
        }
        for(i1=0;i1<n;i1++)
        if(min>=spaces[i1]) min=spaces[i1];
        for(i1=0;i1<n;i1++)
        tsp=tsp+(spaces[i1]-min);
        printf("%d\n",tsp);
}
return 0;
}
