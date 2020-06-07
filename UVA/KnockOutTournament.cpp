#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

#define INF 0x3fffffff
#define e 2.71828182845904523536
#define c 0.57721566490153286060

double hm[1000003];
void preH()
{

    hm[0]=0.0;
    for(int i=1;i<1000003;i++)
    {
        hm[i]+=1.0/((double)i)+hm[i-1];
        //cout<<hm[i]<<endl;
    }
}

double H(int n)
{
    if(n<=1000000) return hm[n];
    return (log((double)n)+c);
}

int main()
{
    preH();
    int w,l,cas=1;
    while(scanf("%d%d",&w,&l)==2&&(w||l))
    {
        if(l==0&&w%8)
        {printf("Case %d:\nSituation Impossible.\n",cas++);continue;}

        int lo=l;
        int hi=(w/8)+l;
        if(l*7<w)
        {
            lo+=(w-l*7)/8;
            if((w-l*7)%8!=0) lo++;
        }
        double tol=(double)(hi-lo+1);
        double total=(double)(w+l);

        double res=total/tol;//printf("tol=%lf and total=%lf res=%lf\n",tol,total,res);
        res*=(H(hi)-H(lo-1));// cout<<res<<endl;
        printf("Case %d:\nOn Average Bob Reaches Round %.2lf\n",cas++,res);
    }


    return 0;
}

