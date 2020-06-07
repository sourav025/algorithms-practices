#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

long long n,a,b;

long long fsum()
{
    if(a==b) {
        return (a%3==0||a%3==2);
    }

    if(b-a==1)
    {
        if((a%3==0||a%3==2) && (b%3==0||b%3==2)) return 2;
        else 1;
    }

    n=b-a+1;
    while(a<b&&(a%3!=1))
        a++;
    int mi=(b-a+1);
    if(mi%3) {mi/=3;mi++;}
    else mi/=3;

    return n-mi;
}


int main()
{
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>a>>b;
        long long res=fsum();
        cout<<"Case "<<cas<<": "<<res<<endl;
    }
    return 0;
}
