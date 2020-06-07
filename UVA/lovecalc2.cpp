#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int mod(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
        if(n==0&&sum>9){n=sum;sum=0;}
    }
    return sum;
}

int main()
{
    int i,j,k,l1,l2;
    char nam1[100],nam2[100];
    while(gets(nam1))
    {
        int sum1=0,sum2=0;
        gets(nam2);
        l1=strlen(nam1);
        l2=strlen(nam2);
        for(i=0;i<l1;i++)
        {
            if(isalpha(nam1[i])!=0){
            nam1[i]=tolower(nam1[i]);
            //printf("%d ",nam1[i]-96);
            sum1+=nam1[i]-96;}
        }

        if(sum1>=10)sum1=mod(sum1);
        for(i=0;i<l2;i++)
        {
            if(isalpha(nam2[i])!=0){
            nam2[i]=tolower(nam2[i]);//printf("%d ",nam2[i]-96);
            sum2+=nam2[i]-96;}
        }//printf("\n");
        if(sum2>=10)sum2=mod(sum2);
    //printf("%d %d",sum1,sum2);
    if(sum1>sum2)printf("%.2f ",((float)sum2/(float)sum1)*100);
    else printf("%.2f ",((float)sum1/(float)sum2)*100);
    printf("%c\n",37);
    }
    return 0;
}
