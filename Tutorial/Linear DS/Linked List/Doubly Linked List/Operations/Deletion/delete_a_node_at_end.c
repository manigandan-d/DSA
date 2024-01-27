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

struct Node *append(struct Node *head, int data)
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

    return head;
}

struct Node *createDLL(struct Node *head)
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

void endDelete(struct Node *head)
{
    struct Node *ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    ptr = NULL;
}

void printData(struct Node *head)
{
    if(head == NULL)
    {
        printf("DLL is Empty\n");
    }
    else
    {
        struct Node *ptr = head;
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main(int argc, char *argv[])
{
    struct Node *head = NULL;

    head = createDLL(head);

    printf("Printing the Data before Deletion\n");
    printData(head);

    endDelete(head);

    printf("Printing the Data after Deletion\n");
    printData(head);

    return 0;
}