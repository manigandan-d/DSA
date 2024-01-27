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

void posInsert(struct Node *head, int data, int pos)
{
    struct Node *ptr, *new;
    ptr = head;
    new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = NULL;

    pos--;
    while(pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    new->link = ptr->link;
    ptr->link = new;
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

    int data, pos;
    printf("Enter the data value : ");
    scanf("%d", &data);
    printf("Enter the pos where you want to insert a node : ");
    scanf("%d", &pos);

    printf("Printing the data before insertion\n");
    printData(head);

    posInsert(head, data, pos);

    printf("Printing the data after insertion\n");
    printData(head);

    return 0;
}