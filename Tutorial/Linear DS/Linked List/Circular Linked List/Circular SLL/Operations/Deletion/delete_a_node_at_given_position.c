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

void posDelete(struct Node *tail, int pos)
{
    struct Node *prev, *cur;
    prev = NULL;
    cur = tail->link;

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

    int pos;
    printf("Enter the position where you want to delete the node : ");
    scanf("%d", &pos);

    printf("Printing the data before Deletion\n");
    printData(tail);

    posDelete(tail, pos);

    printf("Printing the data after Deletion\n");
    printData(tail);

    return 0;
}