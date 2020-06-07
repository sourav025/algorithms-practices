#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<utility>
#include<iostream>
#include<map>
using namespace std;

#define out(pt) cout<<pt.first<<" "<<pt.second<<endl;
#define Max(a,b) ((a>b)?(a):(b))

pair<double,double> pts[800];
map<double,int> mp;
int main()
{
    int t;
    scanf("%d",&t);
    getchar();getchar();
    for(int cas=1;cas<=t;cas++)
    {
        int n=0,a,b;

        while(1)
        {
            string str;
            getline(cin,str);
            if(str=="\0")
                break;
            sscanf(str.c_str(),"%d%d",&a,&b);
            pts[n]=make_pair(a,b);
            n++;
        }
//        getchar();

        int mx=-1;
        for(int i=0;i<n;i++)
        {
            mp.clear();
            for(int j=i+1;j<n;j++)
            {
                double m=double(pts[i].second-pts[j].second ) / double(pts[i].first-pts[j].first);
                mp[m]++;
                mx=Max(mp[m],mx);
            }
        }
        printf("%d\n",mx+1);
        if(cas<t) printf("\n");
    }
    return 0;
}


