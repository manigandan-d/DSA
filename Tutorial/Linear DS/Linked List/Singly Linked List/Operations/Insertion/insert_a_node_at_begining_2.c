#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *link;
};

void begInsert(struct Node **head, int data)
{
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = *head;
    *head = ptr;
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

    struct Node *current = malloc(sizeof(struct Node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct Node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;   

    begInsert(&head, 1); 
    printData(head);
}