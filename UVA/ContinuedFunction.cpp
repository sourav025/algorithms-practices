#include<stdio.h>

int ans[10000],id;

void div(int num,int de)
{
    printf("%d",num/de);
    if(num%de>0){
        if(id==0) printf(";");
        else printf(",");
        id=1;
        div(de,num%de);
    }
}

int main()
{
    int n=43,d=19;

    while(scanf("%d%d",&n,&d)==2)
    {
        id=0;
        printf("[");
        div(n,d);
        printf("]\n");
    }
    return 0;
}
