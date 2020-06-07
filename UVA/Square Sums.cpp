#include<iostream>
using namespace std;
int main()
{
    int sum[10]={0},i,j,cel,k,l,n,a[20][20],cas=1;
    while(cin>>n&&n)
    {
        k=0;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];
        sum[k]=0;
        if(n==1) cel=1;
        else if(n%2==0)
        cel=n/2;
        else cel=(n/2)+1;
        for(l=0;l<cel;l++)
        {
            sum[l]=0;
            for(i=l;i<n-l;i++)
            {
                sum[l]+=a[l][i];
                if(l!=i)
                sum[l]+=a[i][l];
            }
            for(i=n-l-1;i>l;i--)
            {
                sum[l]+=a[n-1-l][i];
                if(i!=n-1-l)
                sum[l]+=a[i][n-1-l];
            }
        }
        cout<<"Case "<<cas++<<":";
        for(i=0;i<cel;i++)
        cout<<" "<<sum[i];
        cout<<endl;
    }
    return 0;
}
