#include<stdio.h>

int main()
{
    int t,n;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);getchar();
        char ch[510],x;
        for(int i=0;i<n;i++)
        {
            scanf("%c",&ch[i]);getchar();
        }
        ch[n]='\0';
        int l=0;bool pnt=0;
        printf("Case %d: ",cas);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<i+3 && j<n;j++)
            {
                if(ch[j]!='W')
                    cnt++;
            }
            if(cnt==3)
            {
                pnt=1;
                printf("%d\n",i+3);break;
            }
        }
        if(!pnt) printf("Yay! Mighty Rafa persists!\n");
    }
    return 0;
}
