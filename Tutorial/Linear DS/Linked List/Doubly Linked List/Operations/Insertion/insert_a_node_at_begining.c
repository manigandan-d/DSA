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

struct Node *begInsert(struct Node *head, int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    head->prev = new;
    new->next = head;
    head = new;
    return head;
}

void printData(struct Node *head)
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char *argv[])
{
    struct Node *head = malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = 5;
    head->next = NULL;

    append(head, 10);
    append(head, 15);

    printf("Printing the Data before Insertion\n");
    printData(head);

    head = begInsert(head, 2);

    printf("Printing the Data after Insertion\n");
    printData(head);

    return 0;
}