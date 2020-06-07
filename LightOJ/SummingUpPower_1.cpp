#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>

#define ull unsigned long long
#define ui unsigned int

ui com[57][57];
int po,len;

using namespace std;

struct mat
{
    ui ar[55][55];
    mat multiply(mat m7)
    {
        mat m8;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++){
                m8.ar[i][j]=0;
                for(int k=0;k<len;k++)
                {
                    m8.ar[i][j]=m8.ar[i][j]+ar[i][k]*m7.ar[k][j];
                }
            }
        }
        return m8;
    }
    mat add(mat ex)
    {
        mat ad;
        for(int i=0;i<len;i++) for(int j=0;j<len;j++) ad.ar[i][j]=ar[i][j]+ex.ar[i][j];
        return ad;
    }
    mat sub(mat ex)
    {
        mat ad;
        for(int i=0;i<len;i++) for(int j=0;j<len;j++) ad.ar[i][j]=ar[i][j]+ex.ar[i][j];
        return ad;
    }

    void print()
    {
        for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++)
                printf("%d",ar[i][j]);
            printf("\n");
        }
    }
};

mat A,m1,m2,m3;

mat power(ull p)
{
    if(p==1LL) return A;
    if((p&1) == 0 )
    {
        m3=power(p>>1);
        m2=m3.multiply(m3);
        return m2;
    }
    else
    {
        m3=power(p-1);
        m2=A.multiply(m3);
        return m2;
    }
}

ui ncr(ui a, ui b) {
    if(b > a/2) {b=a-b;return com[a][b];}
    ui ans=1;
    int i;

    for(i=1; i <= b; i++) {
        ans *= a - b + i;
        ans /= i;
    }
    return ans;
}

void init()
{ /*for(int i=0;i<55;i++)
        for(int j=0;j<=i;j++)
        com[i][j]=ncr(i,j);*/

    com[0][0] = 1;
    for(int i=1;i<=55;i++)
        com[i][0] = 1 , com[i][1] = i , com[i][i] = 1;
    for(int i=2;i<=55;i++)
        for(int j=2;j<i;j++)
            com[i][j] = com[i-1][j] + com[i-1][j-1];
}

int main()
{
    init();
    ///Pascal's Triangle
//    for(int i=0;i<10;i++)
//    {
//        for(int j=0;j<=i;j++)
//        {
//            printf("%d ",com[i][j]);
//        }
//        printf("\n");
//    }
    ull N;
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>N>>po;
        len=po+2;
        A.ar[0][0]=1;A.ar[1][0]=0;
        for(int i=1;i<len;i++)
            A.ar[0][i]=com[po][i-1],A.ar[1][i]=com[po][i-1];

        for(int i=2;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(i>j) {A.ar[i][j]=0;continue;}
                A.ar[i][j]=com[po-i+1][j-i];
            }
        }
        printf("Case %d: ",cas);
        if(N==1LL)
            printf("1\n");
        else if(po==0)
        {
            ui a=N;
            printf("%u\n",a);
        }
        else
        {
            A=power(N-1LL);
            ui sum=0;
            for(int i=0;i<len;i++)
                sum+=A.ar[0][i];
            printf("%u\n",sum);
        }
    }
    return 0;
}
