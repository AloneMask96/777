#include<stdio.h>

void warshal(int adj[10][10], int n)
{
 int i,j,k;
 for(k=1;k<=n;k++)
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
    adj[i][j]= adj[i][j] || adj[i][k] && adj[k][j] ;
}
void main()
{
 int n,i,j,adj[10][10];
 printf("enter the new vertices");
 scanf("%d",&n);
 printf("enter the cost adjacency matrix (enter 999 for infinity)");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
   scanf("%d",&adj[i][j]);
  }
warshal(adj,n);
printf("all pains shortest paths matrix \n ");
for(i=1;i<=n;i++)
{
 for(j=1;j<=n;j++)
 {
  printf("%d \t" , adj[i][j]);
 }
 printf("\n");
 }
}
