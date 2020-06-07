#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long cas,n,m,i,j,f,k,res,l,t,max,min;
    scanf("%llu",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%llu%llu",&n,&m);
        f=0;
        max=0;min=0;
        //cout<<(1<<n);getchar();
        for(i=0;i<(1<<n);i++)
        {
            res=0;
            for(j=n-1;j>=0;j--)
            {
                res=(1<<j)&i?(res*10)+2:(res*10)+1;
            }
            if(res%(1<<m)==0)
            {
                if(f==0)
                {
                    max=res;
                    min=res;
                    f=1;
                }
                if(max<res)max=res;
                if(min>res)min=res;
            }
        }
        printf("Case %llu: ",cas);
        if(max==min&&max!=0) printf("%llu\n",min);

        else if(max!=min)printf("%llu %llu\n",min,max);
        else cout<<"impossible"<<endl;
    }
    return 0;
}
