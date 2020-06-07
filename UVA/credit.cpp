#include<stdio.h>
#include<string.h>
int main()
{
    char crd[100][100];
    int i,j,x,mod,n;
    scanf("%d",&n);
    for(x=0;x<n;x++)
    {
        int k=0,l,ar=0,add2=0,val=0,v=0;
        for(i=0;i<4;i++)
        {
            scanf("%s",crd[i]);
        }
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(j%2==0)
                    {
                        ar=2*(crd[i][j]-'0');
                        if(ar>=10){int l=(ar/10)+(ar%10);ar=l;}
                        val=val+ar; v++;
                    }
                    else if(j%2!=0) {add2=add2+(crd[i][j]-'0');}
                }
            }
            if((add2+val)%10==0)printf("Valid\n");
            else printf("Invalid\n");
        }
    return 0;
}
