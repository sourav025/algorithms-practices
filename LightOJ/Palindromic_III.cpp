#include<bits/stdc++.h>
using namespace std;

char str[100050];

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        cin>>str;
        int len=strlen(str);

        int cnt=1;
        for(int i=(len>>1)-1;i>=0;i--,cnt++)
        {
            cout<<str[i]<<" : "<<str[len-1-i]<<endl;
            if(str[i]<str[len-1-i])
            {

            }
        }
    }
    return 0;
}
