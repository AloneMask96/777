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
    int n, a[100000], choice;
    clock_t t;


    printf("Enter the number of elements: ");
    scanf("%d", &n);


    printf("1. Read from file\n2. Generate random numbers\nChoose an option: ");
    scanf("%d", &choice);

    if (choice == 1)
    {

        FILE* file = fopen("data.txt", "r");
        if (!file) 
        {
            printf("Error: Could not open file.\n");
            return 1;
        }
        for (int i = 0; i < n; i++)
            fscanf(file, "%d", &a[i]);
        fclose(file);
    }
    else
    {

        printf("Generating random numbers:\n");
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 1000;
            printf("%d\n", a[i]);
        }
    }


    t = clock();
    quicksort(a, 0, n - 1);
    t = clock() - t;

    printf("Sorted numbers:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);

    printf("Quicksort took %f seconds.\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}

