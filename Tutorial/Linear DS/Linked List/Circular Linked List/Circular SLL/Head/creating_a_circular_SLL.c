#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *empInsert(struct Node *head, int data)
{
    head = malloc(sizeof(struct Node));
    head->data = data;
    head->link = head;
    return head;
}

struct Node *append(struct Node *head, int data)
{
    struct Node *ptr, *new;
    ptr = head;
    new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = NULL;

    while(ptr->link != head)
    {
        ptr = ptr->link;
    }
    ptr->link = new;
    new->link = head;

    return head;
}

void printData(struct Node *head)
{
    struct Node *ptr = head;

    while(ptr->link != head)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    printf("%d\n", ptr->data);
}

struct Node *create(struct Node *head)
{
    int data, n, i;
    printf("Enter the number of nodes you want : ");
    scanf("%d", &n);

    if(n == 0)
        return head;

    printf("Enter the data value for node 1 : ");
    scanf("%d", &data);
    head = empInsert(head, data);

    for(i=1; i<n; i++)
    {
        printf("Enter the data value for node %d : ", i+1);
        scanf("%d", &data);
        head = append(head, data);
    }

    return head;
}

int main(int argc, char *argv[])
{
    struct Node *head = NULL;
    head = create(head);

    printData(head);
    return 0;
}