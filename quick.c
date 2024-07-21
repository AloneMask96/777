#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap (int a[], int i, int j)
{
int temp;
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
int partition(int a[],int l,int r)
{
int i,j;
int p;
p=a[l];
i=l;
j=r+1;
do
{
do{   i++;}while(a[i]<p);
do{   j--;}while(a[j]>p);
swap(a,i,j);
}while(i<j);
swap(a,i,j);
swap(a,l,j);
return j;
}
void quicksort(int a[], int l, int r)
{
int s;
if(l<r)
{
s=partition(a,l,r);
quicksort(a,l,s-1);
quicksort(a,s+1,r);
}
}
int main()
{
int temp,min,j,i,n,a[100000],choice;
clock_t t;
printf("enter the numbers of elements");
scanf("%d",&n);
printf("1.Read from file 2.Random numbers");
 scanf("%d", &choice);
switch(choice)
{
case 1:
printf("File numbers\n");
FILE*file=fopen("data.txt","r");
int i=0;
while(! feof(file) && i<n)
{
fscanf(file, "%d",&a[i]);
printf("%d\n",a[i]);
i++;
}
fclose(file);
break;
case2:printf("Random number generator");
for(i=0;i<n;i++)
{
a[i]=rand()%1000;
printf("%d\n", a[i]);
}
break;
}
t=clock();
quicksort(a,0,n-1);
t=clock()-t;
double time_taken=((double)t)/CLOCKS_PER_SEC;
printf("entered numbers are after sorting");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
printf("sort function took %f seconds to execute \n",time_taken);
return 0;
}
     

































