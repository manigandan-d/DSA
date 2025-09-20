#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1; 

void push(int value);
void pop();
void peek();
void display();

int main() {
	push(10);
	push(20);
	push(30);
	display();
	peek();

	pop();
	display();
	peek();

	return 0;
}

void push(int value) {
	if(top == MAX-1) {
		printf("Stack Overflow\n");
		return; 
	}

	top++;
	stack[top] = value;

	printf("%d pushed into stack\n", value);
}

void pop() {
	if(top == -1) {
		printf("Stack Underflow\n");
		return; 
	}

	printf("%d popped from stack\n", stack[top]);

	top--;
}

void peek() {
	if(top == -1) {
		printf("Stack is empty\n");
		return; 
	}

	printf("Top element: %d\n", stack[top]);
}

void display() {
	if(top == -1) {
		printf("Stack is empty\n");
		return; 
	}

	printf("Elements: ");

	for(int i=top; i>=0; i--) {
		printf("%d ", stack[i]);
	}

	printf("\n");
}
