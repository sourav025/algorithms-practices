#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

int cmp(const char a, const char b)
{
    int d=tolower(a)-tolower(b);
    return d?(d<0):a<b;
}

int main()
{
    char ar[50];

    int t;cin>>t;getchar();

    while(t--)
    {
        gets(ar);int len=strlen(ar);
        sort(ar,ar+len,cmp);
        do{
            cout<<ar<<endl;
        }while(next_permutation(ar,ar+len,cmp));
    }
    return 0;
}


