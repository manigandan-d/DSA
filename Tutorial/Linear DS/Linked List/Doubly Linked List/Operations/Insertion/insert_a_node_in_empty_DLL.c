#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *empInsert(struct Node *head, int data)
{
    head = malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = data;
    head->next = NULL;
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
    struct Node *head = NULL;

    head = empInsert(head, 5);

    printData(head);

    return 0;
}