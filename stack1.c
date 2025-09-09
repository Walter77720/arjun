#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push()
{
int data;
if (top == MAX - 1) 
{
printf("Stack overflow\n");
} 
else 
{
printf("Enter the value to push: ");
scanf("%d", &data);
stack[++top] = data;
printf("%d pushed to stack\n", data);
}
}
void pop() 
{
if (top == -1)
{
printf("Stack underflow\n");
} 
else 
{
printf("%d popped from stack\n", stack[top]);
top--;
}
}
void display() 
{
if (top == -1) 
{
printf("Stack is empty\n");
} 
else 
{
printf("Stack elements: ");
for (int i = top; i >= 0; i--) 
{
printf("%d ", stack[i]);
}
printf("\n");
}
}
int main() 
{
int choice;
while (1) 
{
printf("\nMenu\n");
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
	push();
	break;
case 2:
	pop();
	break;
case 3:
	display();
	break;
case 4:
	printf("exit");
       return 0;
default:
       printf("invalid choice");
       return 0;
}
}
return 0;
}    

