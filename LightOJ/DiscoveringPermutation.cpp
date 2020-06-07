#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t,n,k;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        char ch[30];
        scanf("%d%d",&n,&k);
        printf("Case %d:\n",cas);
        for(int i=0;i<n;i++)
            ch[i]='A'+i;
        ch[n]='\0';
        do{
            printf("%s\n",ch);
        }while(next_permutation(ch,ch+n)&&--k);

    }
    return 0;
}
