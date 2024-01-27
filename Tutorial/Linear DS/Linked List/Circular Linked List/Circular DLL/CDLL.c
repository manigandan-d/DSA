#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

void empInsert(int data)
{
    tail = malloc(sizeof(struct Node));
    tail->prev = tail;
    tail->data = data;
    tail->next = tail;
}

void begInsert()
{
    int data;
    printf("\nEnter the data for this node : ");
    scanf("%d", &data);

    struct Node *ptr, *new;
    new = malloc(sizeof(struct Node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    ptr = tail->next;
    new->prev = tail;
    new->next = ptr;
    tail->next = new;
    ptr->prev = new;

    printf("Node inserted successfully\n");
}

void endInsert()
{
    int data;
    printf("\nEnter the data for this node : ");
    scanf("%d", &data);

    struct Node *new, *ptr;
    ptr = tail->next;
    new = malloc(sizeof(struct Node));
    new->prev = tail;
    new->data = data;
    new->next = ptr;
    tail->next = new;
    ptr->prev = new;
    tail = new;

    printf("Node inserted successfully\n");
}

void append(int data)
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
}

void posInsert()
{
    int pos, data;
    printf("\nEnter the position where you want to insert a node : ");
    scanf("%d", &pos);
    printf("Enter the data for this node : ");
    scanf("%d", &data);

    struct Node *ptr, *new;
    ptr = tail->next;
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    pos--;
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    new->prev = ptr;
    new->next = ptr->next;
    ptr->next->prev = new;
    ptr->next = new;

    printf("Node inserted successfully\n");
}

void create()
{
    int data, n, i;
    printf("Enter the number of nodes you want : ");
    scanf("%d", &n);

    if(n == 0)
        tail = NULL;

    else
    {
        printf("Enter the data for node 1 : ");
        scanf("%d", &data);
        empInsert(data);

        for(i=1; i<n; i++)
        {
            printf("Enter the data for node %d : ", i+1);
            scanf("%d", &data);
            append(data);
        }
    }
}

void begDelete()
{
    struct Node *ptr = tail->next;
    ptr->next->prev = tail;
    tail->next = ptr->next;
    free(ptr);
    ptr = NULL;

    printf("\nNode at the begining deleted successfully\n");
}

void endDelete()
{
    struct Node *ptr = tail->next;
    ptr->prev = tail->prev;
    tail->prev->next = ptr;
    free(tail);
    tail = ptr->prev;

    printf("\nNode at the end deleted successfully\n");
}

void posDelete()
{
    int pos;
    printf("\nEnter the position where you want to delete the node : ");
    scanf("%d", &pos);
    int p = pos;

    struct Node *ptr = tail->next;

    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    ptr = NULL;

    printf("Node at the position %d deleted successfully\n", p);
}

void delete()
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

    printf("\nCDLL deleted successfully\n");
}

void search()
{
    int element;
    printf("\nEnter the element which you want to search : ");
    scanf("%d", &element);

    int pos = 0, flag = 0;
    
    struct Node *ptr = tail->next;
    
    do
    {
        if(ptr->data == element)
        {
            flag = 1;
            break;
        }
        pos++;
        ptr = ptr->next;
        
    } while (ptr != tail->next);

    if(flag == 1)
        printf("%d is present at position %d in the CDLL\n", element, pos+1);

    else
        printf("%d is not present in the CDLL\n", element);
}

void reverse()
{
    struct Node *prev, *cur, *next;
    prev = tail;
    cur = tail->next;
    next = NULL;

    while(cur != tail)
    {
        next = cur->next;
        cur->prev = next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    next = cur->next;
    cur->prev = next;
    cur->next = prev;
    tail = next;

    printf("\nCDLL reversed successfully\n");
}

void countNodes()
{
    struct Node *ptr = tail->next;
    int count = 0;
    
    do
    {
        count++;
        ptr = ptr->next;
        
    } while (ptr != tail->next);

    printf("\nNumber of Nodes : %d\n", count);
}

void printData()
{
    struct Node *ptr = tail;

    if(ptr == NULL)
        printf("\nCDLL is empty\n");

    else
    {
        ptr = tail->next;
        do
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
            
        } while (ptr != tail->next);
    }
}

int main(int argc, char argv[])
{
    create();

    char s[10];
    int choice = 0;
    while(choice != 12)
    {
        printf("\nIf you want to perform any operations on created CDLL : ");
        scanf("%s", s);

        if(strcmp(s, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. Insert a node at begining\n2. Insert a node at end\n3. Insert a node at given position\n4. Delete a node at begining\n5. Delete a node at end\n6. Delete a node at given position\n7. Delete CDLL\n8. Search for an element\n9. Reverse a CDLL\n10. Counting the number of nodes\n11. Printing the data\n12. Exit\n");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    begInsert();
                    break;
                case 2:
                    endInsert();
                    break;
                case 3:
                    posInsert();
                    break;
                case 4:
                    begDelete();
                    break;
                case 5:
                    endDelete();
                    break;
                case 6:
                    posDelete();
                    break;
                case 7:
                    delete();
                    break;
                case 8:
                    search();
                    break;
                case 9:
                    reverse();
                    break;
                case 10:
                    countNodes();
                    break;
                case 11:
                    printData();
                    break;
                case 12:
                    exit(0);
                    break;
                default:
                    printf("\nPlease Enter the valid choice\n");
            }
        }
        else
            break;
    }

    return 0;
}