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

void posDelete(struct Node *head, int pos)
{
    struct Node *cur, *prev;
    cur = head;
    prev = head;

    while(pos != 1)
    {
        prev = cur;
        cur = cur->link;
        pos--;
    }
    prev->link = cur->link;
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

    int pos;
    printf("Enter the position where you want to delete the node : ");
    scanf("%d", &pos);

    printf("Printing the data before Deletion\n");
    printData(head);

    posDelete(head, pos);

    printf("Printing the data after Deletion\n");
    printData(head);

    return 0;
}