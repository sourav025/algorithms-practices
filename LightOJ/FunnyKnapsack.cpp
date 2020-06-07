#include<stdio.h>
#include<algorithm>
using namespace std;

#define sz (1<<15)

long long left[sz+9],right[sz+9];

int n,w,ar[35],lf,rh;

void fill(int len,int sec)
{
    for(int i=0;i<(1<<len);i++)
    {
        long long sum=0;
        for(int j=0;j<len;j++)
        {
            if((1<<j)&i)
            {
                sum+=( sec?ar[j+(n/2)] : ar[j] );
            }
        }
        if(sum<=w)
        {
            if(sec){
                right[rh++]=sum;
            }
            else {
                left[lf++]=sum;
            }
        }
    }
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        lf=0,rh=0;scanf("%d%d",&n,&w);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        fill(n/2,0);
        fill(n-(n/2),1);

//        printf("left : %d\nRight : %d\n",lf,rh);

        sort(left,left+lf);
        sort(right,right+rh);

        long long comb=0;
//        printf("Left : ->>>> ");
//        for(int i=0;i<lf;i++)
//        {
//            printf("%d ",left[i]);
//        }
//        printf("Left : ->>>> ");
//        for(int i=0;i<rh;i++)
//        {
//            printf("%d ",right[i]);
//        }
//        printf("\n");

        for(int i=0;i<lf;i++)
        {
            int x=w-left[i];

            if(right[0]>x) continue;

            int lo=0,hi=rh;
            while(lo<hi)
            {
                int mid=(lo+hi)>>1;
                if(mid==lo) break;
                if(right[mid]<=x) lo=mid;
                else hi=mid;
            }

//            printf("lo added : %d\n",lo);
            comb+=(lo+1);
        }
        printf("Case %d: %lld\n",cas,comb);
        for(int i=0;i<(sz+9);i++){
            left[i]=0,right[i]=0;
        }
    }
    return 0;
}
