#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node *link; 
};

struct Node *top = NULL; 

int isEmpty();
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

int isEmpty() {
    return top == NULL; 
}

void push(int value) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    if(!new) {
        printf("Stack Overflow (Heap memory full)\n");
        return; 
    }

    new->data = value; 
    new->link = top;
    top = new; 

    printf("%d pushed into stack\n", value);
}

void pop() {
    if(isEmpty()) {
        printf("Stack Underflow\n");
        return; 
    }

    struct Node *temp = top; 
    int popped = temp->data; 
    top = top->link; 
    free(temp);

    printf("%d popped from stack\n", popped);
}

void peek() {
    if(isEmpty()) {
        printf("Stack is empty\n");
        return; 
    }

    printf("Top element: %d\n", top->data);
}

void display() {
    if(isEmpty()) {
        printf("Stack is empty\n");
        return; 
    }

    struct Node *temp = top; 

    printf("Elements: ");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}
