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
struct Node *delete(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}

int main(int argc, char *argv[])
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 5;
    head->link = NULL;

    append(head, 10);
    append(head, 15);

    head = delete(head);

    if(head == NULL)
    {
        printf("Singly Linked List Deleted Successfully");
    }

    return 0;
}