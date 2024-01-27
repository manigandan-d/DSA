#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 50

int stack_arr[max], n;
int top = -1;

void pop();
bool isEmpty();

int main(int argc, char *argv[])
{
    printf("Enter the number of elements you want to push into the stack : ;");
    scanf("%d", &n);

    pop();

    return 0;
}

bool isEmpty()
{
    if(top == -1)
        return true;

    else 
        return false;
}

void pop()
{
    if(isEmpty())
    {
        printf("\nStack Underflow\n");
    }
    top--;
}