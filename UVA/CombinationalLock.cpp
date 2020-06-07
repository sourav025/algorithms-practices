#include<stdio.h>

#define clk true
#define ant false
#define deg 9

#define MIN(a,b) ((a<b)?(a):(b))

int main()
{
    int ar[5];


    while(scanf("%d",&ar[0])==1)
    {
        int chk=ar[0];
        for(int i=1;i<4;i++) {
            scanf("%d",&ar[i]);
            chk=(chk|ar[i]);
        }
        if(chk==0) break;

        int sum=0,xx=0;
        for(int i=1;i<4;i++){
            if(i==1)
                xx=(ar[i-1]-ar[i]+40)%40;
            else if(i==2)
                xx=(ar[i]-ar[i-1]+40)%40;
            else if(i==3)
                xx=(ar[i-1]-ar[i]+40)%40;
            sum+=xx*9;
        }
        printf("%d\n",sum+1080);
    }

    return 0;
}
