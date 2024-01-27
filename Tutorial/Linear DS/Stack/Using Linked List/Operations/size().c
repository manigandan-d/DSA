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
void size();

int main(int argc, char *argv[])
{
    create();

    size();

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

void size()
{
    int count = 0;
    struct Node *ptr = head;

    if(ptr == NULL)
        printf("\nStack is empty\n");

    else
    {
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
    }

    printf("\nNumber of elements in the stack : %d\n", count);
}