#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,l1,l2,t,u,r;
    char s1[30],s2[30];
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++)
    {
        gets(s1);
        gets(s2);
        l1=strlen(s1);
        l2=strlen(s2);
        if(l1==l2)
        {
            int flag=1;
            for(j=0;j<l1;j++)
            {
                 if ((s1[j]=='a')||(s1[j]=='e')||(s1[j]=='i')||(s1[j]=='u')||(s1[j]=='o')||(s1[j]=='0'))
                  {r=0;}
                  else r=1;
                 if ((s2[j]=='a')||(s2[j]=='e')||(s2[j]=='i')||(s2[j]=='u')||(s2[j]=='o')||(s2[j]=='0'))
                 {u=0;}
                 else u=1;
                if(s1[j]!=s2[j]&&(r==1||u==1))
                {
                    flag=0;
                    printf("No\n");
                    break;
                }
            }
            if(flag!=0)
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
