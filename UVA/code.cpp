#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,s,j,k,l,cas=1;
    char ch[110][110];
    while(scanf("%d",&t)==1&&t)
    {
        getchar();
        for(i=0;i<t;i++)
        {
            gets(ch[i]);
        }
        printf("Case %d:\n",cas);
        cout<<"#include<string.h>"<<endl<<"#include<stdio.h>"<<endl;
    cout<<"int main()"<<endl<<"{"<<endl;
        for(i=0;i<t;i++)
        {
            cout<<"printf(\"";
            for(j=0;j<strlen(ch[i]);j++)
            {
                if(isalpha(ch[i][j])==0)
                {
                    if (ch[i][j]=='\\'||ch[i][j]=='\"') cout<<"\\"<<ch[i][j];
                    else cout<<ch[i][j];
                }
                else cout<<ch[i][j];
            }
            cout<<"\\n\");"<<endl;
        }
        cout<<"printf(\"\\n\");"<<endl;
        cout<<"return 0;"<<endl<<"}"<<endl;
        cas++;
    }
    return 0;
}

