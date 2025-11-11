#include<stdio.h>
#include<stdlib.h>
#define max 7
int n;
int adj[max][max];
void create_graph();
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();
int indegree(int v);
int queue[max],front=-1,rear=-1;
int main()
{
int i,v,count,topo_order[max],indeg[max];
create_graph();
for(i=0;i<n;i++)
{
indeg[i]=indegree(i);
if(indeg[i]==0)
insert_queue(i);
}
count=0;
while(!isEmpty_queue()&&count<n)
{
v=delete_queue();
topo_order[count++]=v;
for(i=0;i<n;i++)
{
if(adj[v][i]==1)
{
adj[v][i]=0;
indeg[i]=indeg[i]-1;
if(indeg[i]==0)
insert_queue(i);
}
}
}
if(count<n)
{
printf("\n No Topological ordering is possible,graph contains cycle\n");
exit(1);
}
printf("\n Vertices in topological order are:\n");
for(i=0;i<count;i++)
printf("%d",topo_order[i]+1);
printf("\n");
return 0;
}
void insert_queue(int vertex)
{
if(rear==max-1)
{
printf("\nQueue Overflow\n");
return;
}
if(front==-1)
front=0;
rear=rear+1;
queue[rear]=vertex;
}
int isEmpty_queue()
{
return(front==-1||front>rear);
}
int delete_queue()
{
int del_item;
if(front==-1||front>rear)
{
printf("\n Queue Underflow\n");
exit(1);
}
del_item=queue[front];
front=front+1;
return del_item;
}
int indegree(int v)
{
int i, in_deg = 0;
for(i = 0; i < n; i++)
if(adj[i][v] == 1)
in_deg++;
return in_deg;
}
void create_graph()
{
int i,max_edges,orgin,destin;
printf("\n Enter the no.of Vertices:");
scanf("%d",&n);
max_edges=n*(n-1);
for(i=1;i<=max_edges;i++)
{
printf("Enter edge %d(-1-1 to quit):",i);
scanf("%d%d",&orgin,&destin);
if((orgin==-1)&&(destin==-1))
break;
orgin--;
destin--;
if(orgin>=n||destin>=n||orgin<0||destin<0)
{
printf("\n invalid edge!\n");
i--;
}
else
{
adj[orgin][destin]=1;
}
}
}
