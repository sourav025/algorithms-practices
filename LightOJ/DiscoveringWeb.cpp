#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<string> forward,backward;
string cur,op,link;

int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        while(!forward.empty()) forward.pop();
        while(!backward.empty()) backward.pop();

        cur="http://www.lightoj.com/";
        cout<<"Case "<<cas<<":"<<endl;
        while(true)
        {
            cin>>op;
            if(op=="QUIT") break;
            else if(op=="VISIT")
            {
                cin>>link;
                backward.push(cur);
                cur=link;
                cout<<cur<<endl;
                while(!forward.empty()) forward.pop();
            }
            else if(op=="BACK")
            {
                if(backward.size()==0) {cout<<"Ignored"<<endl;continue;}
                forward.push(cur);
                cur=backward.top();backward.pop();
                cout<<cur<<endl;
            }
            else if(op=="FORWARD")
            {
                if(forward.size()==0) {cout<<"Ignored"<<endl;continue;}
                backward.push(cur);
                cur=forward.top();forward.pop();
                cout<<cur<<endl;
            }
        }
    }
    return 0;
}
