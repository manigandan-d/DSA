#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 10

int stack_arr[max], n;
int top = -1;

void append(int);
void create();
void size();

int main(int argc, char *argv[])
{
    printf("Enter the number of elements you want to push into the stack : ");
    scanf("%d", &n);

    create();

    size();

    return 0;
}

void append(int data)
{
    top++;
    stack_arr[top] = data;
}

void create()
{
    int i, data;
    for(i=1; i<=n; i++)
    {
        printf("Enter the data for the element %d : ", i);
        scanf("%d", &data);
        append(data);
    }
}

void size()
{
    int count = 0, i;
    for(i=top; i>=0; i--)
        count++;

    printf("\nNumber of elements in the stack : %d\n", count);
}


