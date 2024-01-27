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

void countNode(struct Node *tail)
{
    struct Node *ptr = tail->link;
    int count = 0;
    
    do
    {
        count++;
        ptr = ptr->link;
        
    } while (ptr != tail->link);

    printf("Number of Nodes : %d\n", count);
}

int main(int argc, char *argv[])
{
    struct Node *tail = NULL;
    tail = create(tail);

    countNode(tail);

    return 0;
}