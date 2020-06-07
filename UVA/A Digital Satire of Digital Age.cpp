#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char ch[9][25];
int l,r,lsum,rsum;

int lst,rst;

char s1[7];
char s2[7];

void input();
void correct();
void same();
void UpDown();
void DownUp();
void printDot(int len);
void cal_1(int n);
void cal_2(int n);

int main()
{
    //freopen("in.txt","r",stdin);
    int t;scanf("%d",&t);getchar();
    for(int cas=1;cas<=t;cas++)
    {
        lst=0,rst=0;
        input();
        printf("Case %d:\n",cas);
        //printf("l=%d r=%d lsum=%d rsum=%d\n",l,r,lsum,rsum);
        if((l==r&&lsum==rsum)||(l<r&&lsum<rsum)||(l>r&&lsum>rsum))
        {
            correct();
        }
        else
        {
            if(lsum==rsum)
            {
                same();
            }
            else if(lsum<rsum)
            {
                UpDown();
            }
            else DownUp();
        }
        memset(ch,'\0',sizeof(ch));
        memset(s1,'\0',sizeof(s1));
        memset(s2,'\0',sizeof(s2));
    }
    return 0;
}

void input()
{
    bool lf=false;lsum=0;lst=0;rst=0;
    bool rf=false;rsum=0;

    for(int i=0;i<8;i++)
        gets(ch[i]);

    for(int i=0;i<7;i++)
    for(int j=0;j<18;j++)
        if(j<8)
        {
            if(isalpha(ch[i][j]))
                {cal_1(ch[i][j]);s1[lst++]=ch[i][j];}
            else if(ch[i][j]=='/'&&!lf)
                lf=true,l=i;
        }
        else if(j>9&&j<18)
        {
            if(isalpha(ch[i][j]))
                {cal_2(ch[i][j]);;s2[rst++]=ch[i][j];}
            else if(ch[i][j]=='/'&&!rf)
                rf=true,r=i;
        }
}

void correct()
{
    printf("The figure is correct.\n");
}

void same()
{
    printf("........||........\n");
    printf(".../\\...||.../\\...\n");
    printf("../..\\..||../..\\..\n");
    printf("./....\\.||./....\\.\n");
    printf("/%s",s1); printDot(strlen(s1));printf("\\||");

    printf("/%s",s2);printDot(strlen(s2));printf("\\\n");
    printf("\\______/||\\______/\n");
    printf("........||........\n");
}
void UpDown()
{
    printf(".../\\...||........\n");
    printf("../..\\..||........\n");
    printf("./....\\.||.../\\...\n");
    printf("/%s",s1);printDot(strlen(s1));printf("\\||../..\\..\n");
    printf("\\______/||./....\\.\n");
    printf("........||/%s",s2);printDot(strlen(s2));printf("\\\n");
    printf("........||\\______/\n");
}

void DownUp()
{
    printf("........||.../\\...\n");
    printf("........||../..\\..\n");
    printf(".../\\...||./....\\.\n");
    printf("../..\\..||/%s",s2);printDot(strlen(s2));printf("\\\n");
    printf("./....\\.||\\______/\n");
    printf("/%s",s1);printDot(strlen(s1));printf("\\||........\n");
    printf("\\______/||........\n");
}

void printDot(int len)
{
    for(int i=0;i<6-len;i++)
    printf(".");
}

void cal_1(int n)
{
    int zr=0,on=0;
    while(n>0)
    {
        if(n&1)
        {
            on++;
        }
        else zr++;
        n=(n>>1);
    }
    lsum+=(500*on+250*zr);
}
void cal_2(int n)
{
    int zr=0,on=0;
    while(n>0)
    {
        if(n&1)
        {
            on++;
        }
        else zr++;
        n=(n>>1);
    }
    rsum+=(500*on+250*zr);
}
