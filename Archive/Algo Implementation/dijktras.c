#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	union
	{
		int distance;
		int path;
	};
	struct node* next;
}dist;
dist* getnode()
{
	return (dist*)malloc(sizeof(dist));
}

void Dijktras(int **cost,int *source,dist** dst,int n,int s)
{
	int i,u,j,min;
	dist* temp,*tempprev;		
	for(i=1;i<n;i++)					//iterations
	{		
		min=1000;
		for(j=0;j<n;j++)				//for finding u
			if(dst[j]->distance<min && source[j]==0)
			{
				u=j;
				min=dst[j]->distance;
				//appending the destination
				for(temp=dst[u];temp->next;temp=temp->next);
				temp->next=getnode();
				temp->next->path=u;
				temp->next->next=NULL;
				source[u]=1;
				
			}		
		
		for(j=0;j<n;j++)				//updating the distance array after finding u
		{
			if(source[j]==0)
				if(dst[u]->distance+cost[u][j]<dst[j]->distance)
				{
					dst[j]->distance=dst[u]->distance+cost[u][j];
					//copying the path of the u from where j is visited from
					tempprev=dst[u];
					for(temp=dst[j];tempprev->next;temp=temp->next,tempprev=tempprev->next)
					{
						temp->next=getnode();
						temp->next->path=tempprev->next->path;
						temp->next->next=NULL;
					}			
				}							
		}
	}
	
	
	
}

void main()
{
	int **cost;
	int n,*source,i,j,s;
	dist **d,*temp;

	//meeting the prerequisites
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	cost=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		cost[i]=(int*)malloc(sizeof(int)*n);
	source=(int*)malloc(sizeof(int)*n);
	d=(dist**)malloc(sizeof(dist*)*n);
		
	printf("enter the cost adjacency matrix, for infinity enter 1000\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	printf("enter the source vertex, vertex number 0->n-1\n");
	scanf("%d",&s);
	for(i=0;i<n;i++)
	{
		d[i]=getnode();
		d[i]->distance=cost[s][i];
		d[i]->next=NULL;
		source[i]=0;			//initially no vertex is visited
	}
	source[s]=1;				//source is visited
	
	
	//calling algo
	Dijktras(cost,source,d,n,s);		
	


	
	system("clear");			//clearing screen for output
	printf("\t\t\t\tSolution\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\tis the distance from %d to %d and path is\t%d",d[i]->distance,i,s,s);
		for(temp=d[i]->next;temp;temp=temp->next)
			printf("-> %d ",temp->path);
		printf("\n");
	}




	//deallocating memory
	
	for(i=0;i<n;i++)
		free(cost[i]);
	for(i=0;i<n;i++)
		free(d[i]);
	free(cost);
	free(source);
	free(d);
	
}
