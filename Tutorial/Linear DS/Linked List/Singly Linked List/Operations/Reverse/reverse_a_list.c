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
    new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = NULL;

    ptr = head;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = new;
}

struct Node *reverse(struct Node *head)
{
    struct Node *prev, *next;
    prev = NULL;
    next = NULL;

    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
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

    printf("Printing the Data before Reverse Operation\n");
    printData(head);

    head = reverse(head);

    printf("Printing the Data after Reverse Operation\n");
    printData(head);

    return 0;
}