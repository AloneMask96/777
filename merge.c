#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int merge(int b[],int c[],int a[],int p,int q,int n)
{
  int i,j,k;
  i=j=k=0;
  while(i<p && j<q)
  {
    if(b[i]<=c[j])
    {
      a[k]=b[i];
      i++;
    }
    else
    {
      a[k]=c[j];
      j++;
    }
      k++;
  }
  if(i==p)
  {
    while(j<q)
    {
      a[k]=c[j];
      k++;
      j++;
    }
  }
  else
  {
    while(i<p && k<n)
      a[k++]=b[i++];
  }
 }
 int mergesort(int a[],int n)
 {
   int b[n/2];
   int c[n-n/2];
   int i,j;
   if(n>1)
   {
     for(i=0;i<n/2;i++)
       b[i]=a[i];
     for(i=n/2,j=0;i<n;i++,j++)
       c[j]=a[i];
     mergesort(b,n/2);
     mergesort(c,n-n/2);
     merge(b,c,a,n/2,n-n/2,n);
   }
}
int main()
{
  int temp,min,j,i,n,a[100000],choice;
  clock_t t;
  printf("enter the number of elements :");
  scanf("%d",&n);
  printf("1. Read from file	2. Random numbers");
  scanf("%d",&choice);
  switch(choice)
  {
     case 1:
          printf("file numbers\n");
          FILE *file = fopen("num.txt","r");
          int i=0;
          while(!feof(file) && i<n)
          {
             //printf("%d ",i+1);
             fscanf(file,"%d",&a[i]);
             printf("%d\n",a[i]);
             i++;
          }
          fclose(file);
          break;
     case 2:
          printf("Random number generator");
          for(i=0;i<n;i++)
          {
             a[i] = rand()%1000;
             printf("%d\n",a[i]); 
          }
          break;
  }
  t = clock();
  mergesort(a,n);
  t = clock()-t;
  double time =((double)t)/CLOCKS_PER_SEC;
  printf("entered number after sorting\n");
  for (i=0;i<n;i++)
     printf("%d\n",a[i]);
  printf("sort function took %f sec to execute",time);
  return 0;
  }
