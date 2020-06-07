#include<stdio.h>

int nexthi_same_count_ones(int a) {
/* works for any word length */
    int c = (a & -a);
    int r = a+c;
    return ((((r ^ a) >> 2) / c) | r);
}

int main()
{
    int t,cas,n;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",cas,nexthi_same_count_ones(n));
    }

    return 0;
}
