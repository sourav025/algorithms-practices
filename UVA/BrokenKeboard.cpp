#include<stdio.h>
#include<string.h>
#include<string>
#include<list>
#include<iostream>
using namespace std;

int main()
{
    char str[100009];
    list<char>lst;
    list<char>::iterator it;
    while(gets(str))
    {
		int len=strlen(str);
        it=lst.begin();
		for(int i=0;i<len;i++){
            if(str[i]=='[') it=lst.begin();
            else if(str[i]==']') it=lst.end();
            else lst.insert(it,str[i]);
		}
		for(it=lst.begin();it!=lst.end();it++)
		{
            cout<<*it;
		}
		cout<<endl;
		lst.clear();
    }
    return 0;
}
