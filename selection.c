#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
  int temp,min,j,i,n,a[100000],choice;
  clock_t t;
  printf("enter the number of elements :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   a[i]=rand()%1000;
   printf("\n%d",a[i]);
  }
  t = clock();
  for(i=0;i<=n-2;i++)
 {
 min = i;
 for(j=i+1;j<=n-1;j++)
 {
  if(a[j] <a[min])
     min = j;
 }
 temp = a[i];
 a[i] = a[min];
 a[min] = temp;
}
  t = clock()-t;
  double time =((double)t)/CLOCKS_PER_SEC;
  printf("entered number after sorting\n");
  for (i=0;i<n;i++)
     printf("%d\n",a[i]);
  printf("sort function took %f sec to execute",time);
  return 0;
  }













