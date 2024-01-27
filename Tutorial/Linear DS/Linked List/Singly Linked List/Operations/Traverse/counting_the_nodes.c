#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void countNodes(struct Node *head)
{
    int count = 0;
    struct Node *ptr = head;

    if(ptr == NULL)
        printf("Singly Linked List is Empty\n");
    
    else
    {
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
    }

    printf("Number of Nodes : %d\n", count);
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

    countNodes(head);

    return 0;
}