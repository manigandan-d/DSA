#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *empInsert(struct Node *tail, int data)
{
    tail = malloc(sizeof(struct Node));
    tail->prev = tail;
    tail->data = data;
    tail->next = tail;

    return tail;
}

struct Node *append(struct Node *tail, int data)
{
    struct Node *new, *ptr;
    ptr = tail->next;
    new = malloc(sizeof(struct Node));
    new->prev = tail;
    new->data = data;
    new->next = ptr;
    tail->next = new;
    ptr->prev = new;
    tail = new;

    return tail;
}

struct Node *create(struct Node *tail)
{
    int n, data, i;
    printf("Enter the number of nodes you want : ");
    scanf("%d", &n);

    if(n == 0)
        return tail;

    else
    {
        printf("Enter the data for node 1 : ");
        scanf("%d", &data);
        tail = empInsert(tail, data);

        for(i=1; i<n; i++)
        {
            printf("Enter the data for node %d : ", i+1);
            scanf("%d", &data);
            tail = append(tail, data);
        }

        return tail;
    }
}

struct Node *delete(struct Node *tail)
{
    struct Node *head, *next;
    head = tail->next;
    next = NULL;

    do
    {
        next = head->next;
        free(head);
        head = next;
    } while (head != tail->next);
    tail = NULL;

    return tail;
    
}

void printData(struct Node *tail)
{
    struct Node *ptr = tail->next;

    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;

    } while (ptr != tail->next);
    
}

int main(int argc, char *argv[])
{
    struct Node *tail = NULL;
    tail = create(tail);

    tail = delete(tail);

    if(tail == NULL)
    {
        printf("Circular DLL deleted successfully\n");
    }

    return 0;
}