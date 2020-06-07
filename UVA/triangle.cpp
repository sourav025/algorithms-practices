#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,n,t,s;
    scanf("%d",&s);
    printf("\n");
    while(s>0){
    scanf("%d%d",&n,&t);
    printf("\n");
    for(k=0;k<t;k++){
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }
    for(i=n-1;i>0;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }
    if(k!=t-1)
    printf("\n");
    }s--;}
    return 0;
}
