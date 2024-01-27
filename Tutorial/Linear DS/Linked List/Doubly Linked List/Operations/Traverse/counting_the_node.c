#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void append(struct Node *head, int data)
{
    struct Node *ptr, *new;
    new = malloc(sizeof(struct Node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->prev = ptr;
}

void countNode(struct Node *head)
{
    struct Node *ptr = head;
    int count = 0;

    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    printf("Number of Nodes : %d\n", count);
}

int main(int argc, char *argv[])
{
    struct Node *head = malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = 5;
    head->next = NULL;

    append(head, 10);
    append(head, 15);

    countNode(head);

    return 0;
}