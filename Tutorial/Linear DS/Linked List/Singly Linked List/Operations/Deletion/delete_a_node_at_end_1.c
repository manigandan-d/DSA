#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void append(struct Node *head, int data)
{
    struct Node *ptr, *new;
    ptr = head;
    new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = new;
}

void endDelete(struct Node *head)
{
    struct Node *prev, *cur;
    prev = head;
    cur = head;

    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    free(cur);
    cur = NULL;
}

void printData(struct Node *head)
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

int main(int argc, char *argv[])
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 5;
    head->link = NULL;

    append(head, 10);
    append(head, 15);

    printf("Printing the data before Deletion\n");
    printData(head);

    endDelete(head);
    printf("Printing the data after Deletion\n");
    printData(head);

    return 0;
}