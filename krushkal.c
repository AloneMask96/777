#include<stdio.h>

	
	void main() 
	{
	
		int mincost=0,n,i,j,ne,a = 0,b = 0,min,u = 0,v = 0;			
		int cost[10][10],parent[10];
		printf("Enter the number of vertices\n");
		scanf("%d",&n);
		
		printf("Enter the cost matrix\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&cost[i][j]);
				if(cost[i][j]==0)
					cost[i][j]=999;
			}
		}
		ne=1;
		printf("Minimum cost spanning tree edges\n");
		while(ne<n)
		{
			for(min=999,i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
					if(cost[i][j]<min)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
			}
			while(parent[u]!=0)
				u=parent[u];
			while(parent[v]!=0)
				v=parent[v];
			if(v!=u)
			{
				printf("%d:(%d->%d)=%d\n",ne++,a,b,min);
				mincost+=min;
				parent[v]=u;
			}
			cost[a][b]=cost[b][a]=999;
		}
		printf("The minimum cost of spanning tree is =%d ",mincost);
	}
