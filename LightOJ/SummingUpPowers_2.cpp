#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
int len,k;

struct mat
{
    int ar[35][35];
    mat multiply(mat m7)
    {
        mat m8;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++){
                m8.ar[i][j]=0;
                for(int k=0;k<len;k++)
                {
                    m8.ar[i][j]=(m8.ar[i][j]+(ar[i][k]*m7.ar[k][j])%10)%10;
                }
            }
        }
        return m8;
    }
    mat add(mat ex)
    {
        mat ad;
        for(int i=0;i<len;i++) for(int j=0;j<len;j++) ad.ar[i][j]=(ar[i][j]+ex.ar[i][j])%10;
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

    void fill_I()
    {
        for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            ar[i][j]=(i==j);
    }
};


mat A,m1,m2,m3;

mat power(int p)
{
    if(p==1) return A;
    if(p%2==0)
    {
        m3=power(p/2);
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

mat I;

mat getSum(int x)
{
    if(x==1) return A;
    if(x%2==1)
    {
        mat ex=getSum(x-1);
        mat pw=power(x);
        ex=ex.add(pw);
        return ex;
    }
    else {
        ///This is also Correct
        /*
        mat ex = getSum(x/2);
        mat pw = power(x/2);
        pw = pw.multiply(ex);
        return ex.add(pw);
        */
        ///Other Way
        mat pw=power(x>>1);
        pw=I.add(pw);
        mat ex=getSum(x>>1);
        return ex.multiply(pw);
    }
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&len,&k);
        I.fill_I();
        for(int i=0;i<len;i++) for(int j=0;j<len;j++) {scanf("%d",&A.ar[i][j]);A.ar[i][j]%=10;}
        printf("Case %d:\n",cas);
        mat res= getSum(k);
        //printf("(O(lgN)):\n");
        res.print();
//        for(int i=2;i<=k;i++)
//        {
//            res=res.add(power(i));
//        }
//
//        res.print();
    }
    return 0;
}
/*
2

4 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

*/
