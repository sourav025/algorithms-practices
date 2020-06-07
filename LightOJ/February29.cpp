#include<stdio.h>
#include<map>
#include<sstream>
#include<iostream>
using namespace std;


void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

bool leapYear(int year)
{
    return ((year%4==0 && year%100)||(year%400==0));
}

int noTo(int from,int to,int by)
{
    if(to<from) return 0;
    if(from%by)
        from=from+(by-(from%by));

    if(from>to) return 0;
    return ((to-from)/by)+1;
}

int monStoI(string mon);


int main()
{

//    freopen("in.txt","r",stdin);

    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        string m;

        int day,day2,mon,mon2,yr,yr2;

        cin>>m;
        scanf("%d, %d",&day,&yr);
        mon=monStoI(m);

        cin>>m;
        scanf("%d, %d",&day2,&yr2);
        mon2=monStoI(m);

///Date assemble

        if(yr>yr2)
        {
            swap(day,day2);swap(mon,mon2);swap(yr,yr2);
        }
        else if(yr==yr2)
        {
            if(mon>mon2)
            {
                swap(day,day2);swap(mon,mon2);
            }
            else if(mon==mon2)
            {
                if(day>day2)
                    swap(day,day2);
            }
        }

/// main Calculation
        int total=0;
        if(yr==yr2 && leapYear(yr) )
        {
            if(mon<=2 && (mon2>2 || (mon2==2 && day2==29) ) ) total=1;
        }
        else
        {
            total=0;

            if(!leapYear(yr) || mon>2)
            {
                yr++;
            }
            if(!leapYear(yr2) || mon2<2 || (mon2==2 && day<29) )
            {
                yr2--;
            }

            int by4=noTo(yr,yr2,4);
            int by100=noTo(yr,yr2,100);
            int by400=noTo(yr,yr2,400);

            total=total+by4-by100+by400;

        }

        printf("Case %d: %d\n",cas,total);

    }
    return 0;
}

int monStoI(string mon)
{
    if(mon=="January")
    {
        return 1;
    }
    if(mon=="February")
    {
        return 2;
    }
    if(mon=="March")
    {
        return 3;
    }
    if(mon=="April")
    {
        return 4;
    }
    if(mon=="May")
    {
        return 5;
    }
    if(mon=="June")
    {
        return 6;
    }
    if(mon=="July")
    {
        return 7;
    }
    if(mon=="August")
    {
        return 8;
    }
    if(mon=="September")
    {
        return 9;
    }
    if(mon=="October")
    {
        return 10;
    }
    if(mon=="November")
    {
        return 11;
    }
    if(mon=="December")
    {
        return 12;
    }
}

/*
4
January 12, 2012
March 19, 2012
August 12, 2899
August 12, 2901
August 12, 2000
August 12, 2005
February 29, 2004
February 29, 2001
*/
