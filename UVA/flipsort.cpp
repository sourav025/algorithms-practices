#include <stdio.h>
int main()
{
  int i,n,j,t,arr[1010],count;
  while(scanf("%d",&n)==1&&n)
  {
      count=0;
      for(i=0;i<n;i++)
      {
          scanf("%d",&arr[i]);
      }
      for(i=0;i<n;i++)
      {
          for(j=0;j<n-1;j++)
          {
              if(arr[j]>arr[j+1])
              {
                  count++;
                  t=arr[j];
                  arr[j]=arr[j+1];
                  arr[j+1]=t;
              }
          }
      }
  printf("Minimum exchange operations : %d\n",count);
  }
  return 0;
}

