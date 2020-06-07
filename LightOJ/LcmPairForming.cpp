#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        long long n,dv=1;
        scanf("%lld",&n);
        int len=sqrt((double)n);

        vector<long long> ele,val;

        for(int i=2;i<=len;i++)
        {
            int cnt=0;
            while(n%i==0&&n>1)
                cnt++,n/=i;
            if(cnt>0){
                ele.push_back(i);
                val.push_back(cnt+1);
            }
            dv*=(cnt+1);
        }
        if(n>1) {
            dv*=2;
            ele.push_back(n);
            val.push_back(2);
        }
        for(int i=0;i<ele.size();i++)
        {
            for(int j=0;j<val.size();j++)
            {

            }
        }


        printf("Case %d: %d\n",cas,dv);
    }
    return 0;
}
