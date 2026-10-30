#include<stdio.h>
#define INF 99999
int graph[10][10],dist[10],sptset[10],vertices;
void dijkstra(int src)
{
	for(int i=0;i<vertices-1;i++){
		dist[i]=INF;
		sptset[i]=0;
	}
	dist[src]=0;
	for(int count=0;count<vertices-1;count++)
	{
		int min=INF;
		int u=-1;
	
	    for(int v=0;v<vertices;v++)
		{
		    if(sptset[v]==0 && dist[v]<=min)
			{
		     	min=dist[v];
			    u=v;
			}
		}
	
	    sptset[u]=1;
	    for(int v=0;v<vertices;v++)
		{
			
		    if(!sptset[v] && graph[u][v] && dist[u]!=INF && dist[u]+graph[u][v]<dist[v]);
		   {
		    dist[v]=graph[u][v]+dist[u];
		   }
		}
	    
	}
	printf("the shortest distance from source %d to every vertex is\n",src);
	for(int i=0;i<vertices;i++)
	{
		printf("edges (%d---%d)",i,dist[i]);
	}
	
}
int main(){
	int src;
	printf("Enter the no of verticees\n");
	scanf("%d",&vertices);
	printf("Enter the adjacency matrix\n");
	for(int i=0;i<vertices;i++){
		for(int j=0;j<vertices;j++){
			scanf("%d",&graph[i][j]);
			
		}
		
	}
	printf("Enter the source vertices\n");
	scanf("%d",&src);
	dijkstra(src);
	return 0;
}

