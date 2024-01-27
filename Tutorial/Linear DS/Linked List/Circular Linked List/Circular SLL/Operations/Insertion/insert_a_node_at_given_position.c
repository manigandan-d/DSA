#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *empInsert(struct Node *tail, int data)
{
    tail = malloc(sizeof(struct Node));
    tail->data = data;
    tail->link = tail;

    return tail;
}

struct Node *append(struct Node *tail, int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = tail->link;
    tail->link = new;
    tail = new;

    return tail;
}

void begInsert(struct Node *tail, int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = tail->link;
    
    tail->link = new;
}

void posInsert(struct Node *tail, int pos, int data)
{
    struct Node *ptr, *new;
    ptr = tail->link;

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

struct Node *create(struct Node *tail)
{
    int data, n, i;
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

void printData(struct Node *tail)
{
    struct Node *ptr = tail->link;
    
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
        
    } while (ptr != tail->link);
    
    
}

int main(int argc, char *argv[])
{
    struct Node *tail = NULL;
    tail = create(tail);

    int data, pos;
    printf("Enter the position where you want to insert a node : ");
    scanf("%d", &pos);
    printf("Enter the data : ");
    scanf("%d", &data);

    printf("Printing the data before Insertion\n");
    printData(tail);

    posInsert(tail, pos, data);

    printf("Printing the data before Insertion\n");
    printData(tail);

    return 0;
}