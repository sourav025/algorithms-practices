///Mod(O(lgN))

#include<cstdio>
#include<cmath>
using namespace std;

typedef unsigned long long Long;

Long cross(Long A, Long B)
{
    A%=mod; B%=mod;
    Long ret = 0, b;
    while(B)
    {
        b = B%2;
        ret = (ret + A*b)%mod;
        B /= 2;
        A = (A*2)%mod;
    }
    return ret;
}

int main()
{
    return 0;
}