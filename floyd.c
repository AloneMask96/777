#include<stdio.h>
int min(int a, int b)
{
 return(a<b)? a: b ;
}
void floyds(int cost[10][10], int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    cost[i][j]= min(cost[i][j], cost[i][k] + cost[k][j]);
}
void main()
{
 int n,i,j,cost[10][10];
 printf("enter the new vertices");
 scanf("%d",&n);
 printf("enter the cost adjacency matrix (enter 999 for infinity)");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
  }
floyds(cost,n);
printf("all pains shortest paths matrix \n ");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
  printf("%d \t" , cost[i][j]);
 }
 printf("\n");
 }
}
