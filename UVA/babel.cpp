#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k,flag2=0;
    char str[50],str1[50],str2[50],str3[100];
    map<string,string>mp;
    map<string,string>::iterator it;
    while(gets(str3))
    {
        if(str3[0]=='\0') break;
        else
        {
            flag2=1;
            int l=strlen(str3),flag=0,m=0,n=0;
            for(i=0;i<l-1;i++)
            {
                if(str3[i]!=' '&&flag==0)
                {
                    str1[m++]=str3[i];
                }
                else
                {
                    flag=1;
                    str2[n++]=str3[i+1];
                }
            }
            str1[m]='\0';
            str2[n]='\0';
            mp[str2]=str1;
        }
    }
    if(flag2)
    {
        while(gets(str))
        {
            if(str[0]=='\0') break;
            else if(mp[str]=="\0")
            cout<<"eh"<<endl;
            else
            cout<<mp[str]<<endl;
        }
    }
    return 0;
}


