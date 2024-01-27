#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 50

int stack_arr[max], n;
int top = -1;

void push();
bool isFull();

int main(int argc, char *argv[])
{
    printf("Enter the number of elements you want to push into the stack : ");
    scanf("%d", &n);

    push();
    return 0;
}

bool isFull()
{
    if(top == n-1)
        return true;

    else
        return false;
}

void push()
{
    if(isFull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    printf("Enter the data for this element : ");
    scanf("%d", &stack_arr[top]);
}