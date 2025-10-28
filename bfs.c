#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
struct vertex 
{
char data;
bool visited;
};
struct vertex *graph[MAX];
int adj_matrix[MAX][MAX];
int queue[MAX];
int rear = -1;
int front = 0;
int queue_count = 0;
int vertex_count = 0;
void enqueue(int data) 
{
queue[++rear] = data;
queue_count++;
}
int dequeue() 
{
queue_count--;
return queue[front++];
}
bool is_queue_empty() 
{
return queue_count == 0;
}
void add_vertex(char data) 
{
struct vertex *new = (struct vertex *)malloc(sizeof(struct vertex));
new->data = data;
new->visited = false;
graph[vertex_count++] = new;
}
void add_edge(int start, int end) 
{
adj_matrix[start][end] = 1;
adj_matrix[end][start] = 1;
}
int adj_vertex(int vertex_get) 
{
for (int i = 0; i < vertex_count; i++) 
{
if (adj_matrix[vertex_get][i] == 1 && graph[i]->visited == false)
return i;
}
return -1;
}
void display_vertex(int pos) 
{
printf("%c -> ", graph[pos]->data);
}
void bfs(struct vertex *new, int start) 
{
if (!new) 
{
printf("\nNothing to display\n");
return;
}
int unvisited;
printf("\n|||||||||||||||||||||||||||||||\n");
new->visited = true;
display_vertex(start);
enqueue(start);
while (!is_queue_empty()) 
{
int pop_vertex = dequeue();
while ((unvisited = adj_vertex(pop_vertex)) != -1) 
{
graph[unvisited]->visited = true;
display_vertex(unvisited);
enqueue(unvisited);
}
}
printf("\n|||||||||||||||||||||||||||||||\n");
for (int i = 0; i < vertex_count; i++)
graph[i]->visited = false;
}
void show() 
{
printf("\n.................................\n");
for (int i = 0; i < vertex_count; i++) 
{
printf("Edge position of '%c' is %d\n", graph[i]->data, i);
}
printf(".................................\n");
}
int main() 
{
int opt;
char data;
int edge_1, edge_2;
int i, j;
int start;
for (i = 0; i < MAX; i++)
for (j = 0; j < MAX; j++)
adj_matrix[i][j] = 0;
do 
{
printf("\n1) Add vertex");
printf("\n2) Create edge");
printf("\n3) Traversal (BFS)");
printf("\n0) Exit");
printf("\nChoose option :: ");
scanf("%d", &opt);
switch (opt) 
{
case 1:
printf("\nEnter data to be added to vertex : ");
scanf(" %c", &data);
add_vertex(data);
break;
case 2:
show();
printf("\nEnter edge starting (position): ");
scanf("%d", &edge_1);
printf("Enter edge ending (position): ");
scanf("%d", &edge_2);
if (vertex_count - 1 < edge_1 || vertex_count - 1 < edge_2) 
{
printf("\nThere is no vertex !!\n");
}
else 
{
add_edge(edge_1, edge_2);
printf("\n---------------------------------\n");
printf("Starting node : %c\n", graph[edge_1]->data);
printf("Edge node     : %c\n", graph[edge_2]->data);
printf("Connected     : %c -- %c\n", graph[edge_1]->data, graph[edge_2]->data);
printf("---------------------------------\n");
printf("\nCurrent connections:\n");
for (i = 0; i < vertex_count; i++) 
{
for (j = i + 1; j < vertex_count; j++) 
{
if (adj_matrix[i][j] == 1) 
{
printf("%c -- %c\n", graph[i]->data, graph[j]->data);
}
}
}
printf("---------------------------------\n");
}
break;
case 3:
printf("\nEnter starting vertex position : ");
scanf("%d", &start);
bfs(graph[start], start);
break;
case 0:
printf("\nExiting program...\n");
break;
default:
printf("\nInvalid option! Try again.\n");
}
} 
while (opt != 0);
return 0;
}


