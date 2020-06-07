#include<stdio.h>

int swap(int &a,int &b)
{
   int t=a;a=b,b=t;
}

int main()
{
    int r,a,b;
    while(scanf("%d%d%d",&r,&a,&b)==3)
    {
        if(a>b) swap(a,b);
        bool flag=0;
        while(!flag)
        {
            if((((1<<(r-1)) == a)) || ((1<<(r-1)) > a && (1<<(r-1)) < b))
            {
                flag=1;
            }
            else if((1<<(r-1)) < a)
            {
                a-=(1<<(r-1));
                b-=(1<<(r-1));
            }
            else if( (1<<(r-1)) >= b )
            {
                r--;
            }
            else if( (1<<(r-1)) < b  )
            {
                a-=(1<<(r-1));
                b-=(1<<(r-1));
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
