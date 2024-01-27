#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;

void append(int);
void create();
void peek();

int main(int argc, char *argv[])
{
    create();

    peek();

    return 0;
}

void append(int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    if(new == NULL)
        printf("\nStack Overflow\n");

    else
    {
        new->data = data;
        new->link = head;
        head = new;
    }
}

void create()
{
    int data, i, n;
    printf("Enter the number of elements you want to push onto the stack : ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Enter the data for the element %d : ", i);
        scanf("%d", &data);
        append(data);
    }
}

void peek()
{
    printf("\nElement at the top of the stack : %d\n", head->data);
}