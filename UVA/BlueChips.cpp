#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int len,round,dist;

struct mat
{
    int ar[55][55];
    mat multiply(mat m7)
    {
        mat m8;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++){
                m8.ar[i][j]=0;
                for(int k=0;k<len;k++)
                {
                    m8.ar[i][j]=(m8.ar[i][j]+ar[i][k]*m7.ar[k][j]);
                    m8.ar[i][j]%=len;
                }
            }
        }
        return m8;
    }

    void print()
    {
        for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++) printf("%d ",ar[i][j]);
            printf("\n");
        }
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

int given[55];

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d",&len,&round,&dist);

        memset(given,0,sizeof(given));

        for(int i=0;i<len;i++){
            scanf("%d",&given[i]);
            given[i]%=len;
        }

        memset(A.ar,0,sizeof(A.ar));

        int l,r;

        for(int i=0;i<len;i++)
        {
            for(int j=1;j<=dist;j++)
            {
                l=i-j+len;
                l%=len;

                r=i+j;
                r%=len;

                A.ar[i][l]=1;
                A.ar[i][r]=1;
            }
            A.ar[i][i]=0;
        }

//        A.print();

        m1=power(round);

        int mini,cnt=0; vector<int> res;res.clear();

        for(int i=0;i<len;i++)
        {
            int sum=0;
            for(int j=0;j<len;j++)
            {
                m1.ar[i][j]*=given[j];
                sum+=m1.ar[i][j];
            }
            sum%=len;
            res.push_back(sum);
            if(i==0) mini=sum;
            if(mini > sum ) mini=sum;
        }

        printf("%d\n",mini);
        bool flag=0;
        for(int i=0;i<len;i++)
        {
            if(res[i]==mini){
                if(flag) printf(" ");
                printf("%d",i+1);
                flag=1;
            }
        }
        printf("\n");
    }
    return 0;
}
