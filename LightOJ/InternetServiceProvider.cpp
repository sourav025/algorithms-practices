#include<stdio.h>

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n,c,res;
        scanf("%d%d",&n,&c);
        if(n==0||c==0)
        {
            res=0;
        }
        else
        {
            double a=c,b=(2*n);
            a/=b;
            res=(int)a;
            if(a-res>0.50)
            {
                res++;
            }
        }
        printf("Case %d: %d\n",cas,res);


    }
    return 0;
}
