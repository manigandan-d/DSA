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

void posInsert(struct Node *head, int pos, int data)
{
    struct Node *ptr, *new; 
    new = malloc(sizeof(struct Node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    ptr = head;

    pos--;
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr->next->prev = new;
    new->next = ptr->next;
    new->prev = ptr;
    ptr->next = new;
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

    int pos, val;
    printf("Enter the position where you want to insert a node : ");
    scanf("%d", &pos);
    printf("Enter the data value : ");
    scanf("%d", &val);

    printf("Printing the Data before Insertion\n");
    printData(head);

    posInsert(head, pos, val);

    printf("Printing the Data after Insertion\n");
    printData(head);

    return 0;
}