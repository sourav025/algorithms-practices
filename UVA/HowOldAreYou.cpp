#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

int a,b,c,d,e,f;
char ch[30],ch2[30];
void Num()
{
        char *p,*q;
        p=strtok(ch,"/");
        a=atoi(p);
        p=strtok('\0',"/");
        b=atoi(p);
        p=strtok('\0',"/");
        c=atoi(p);
        q='\0';
        q=strtok(ch2,"/");
        d=atoi(q);
        q=strtok('\0',"/");
        e=atoi(q);
        q=strtok('\0',"/");
        f=atoi(q);
        memset(ch,'\0',strlen(ch)+2);
        memset(ch2,'\0',strlen(ch2)+2);
}
int main()
{

    int t,i,j,k=1,l,age;
    float c1,c2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",ch,ch2);
        Num();
        printf("Case #%d: ",k++);
        //printf("%d %d %d \n%d %d %d\n",a,b,c,d,e,f);
        c1=(float)c+(((float)b)/12)+(((float)a)/(30*12));
        c2=(float)f+(((float)e)/12)+(((float)d)/(30*12));
        if(c1<c2)
        {
            printf("Invalid birth date\n");
        }
        else
        {
            if(a<d)e++;
            if(b<e)f++;
            age=c-f;
            if(age>130)
            printf("Check birth date\n",age);
            else cout<<age<<endl;
        }
    }
    return 0;
}
/*3
122/232/3444
232/324/3443*/
