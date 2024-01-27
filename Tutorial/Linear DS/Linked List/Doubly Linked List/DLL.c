#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void empInsert(int data)
{
    head = malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = data;
    head->next = NULL;
}

void begInsert()
{
    int data;
    printf("\nEnter the data for this node : ");
    scanf("%d", &data);

    struct Node *new = malloc(sizeof(struct Node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    new->next = head;
    head->prev = new;
    head = new;

    printf("Node inserted successfully\n");
}

void endInsert()
{
    int data;
    printf("\nEnter the data for this node : ");
    scanf("%d", &data);

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

    printf("Node inserted successfully\n");
}

void append(int data)
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
}

void posInsert()
{
    int pos, data;
    printf("\nEnter the position where you want to insert a node : ");
    scanf("%d", &pos);
    printf("Enter the data for this node : ");
    scanf("%d", &data);

    struct Node *ptr, *new; 
    new = malloc(sizeof(struct Node));
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    ptr = head;

    pos--;
    while(pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr->next->prev = new;
    new->next = ptr->next;
    new->prev = ptr;
    ptr->next = new;

    printf("Node inserted successfully\n");
}

void create()
{
    int data, n, i;
    printf("Enter the number of nodes you want : ");
    scanf("%d", &n);
    
    if(n == 0)
        head = NULL;
    
    printf("Enter the data value for node 1 : ");
    scanf("%d", &data);
    empInsert(data);

    for(i=1; i<n; i++)
    {
        printf("Enter the data value for node %d : ", i+1);
        scanf("%d", &data);
        append(data);
    }
}

void begDelete()
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;

    printf("\nNode at the begining deleted successfully\n");
}

void endDelete()
{
    struct Node *ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    ptr = NULL;

    printf("\nNode at the end deleted successfully\n");
}

void posDelete()
{
    int pos;
    printf("\nEnter the position where you want to delete the node : ");
    scanf("%d", &pos);
    int p = pos;

    struct Node *ptr = head;
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
    struct Node *temp = head;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("\nDLL deleted successfully\n");
}

void search()
{
    int element;
    printf("\nEnter the element which you want to search : ");
    scanf("%d", &element);

    int pos = 0, flag = 0;
    
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        if(ptr->data == element)
        {
            flag = 1;
            break;
        }
        pos++;
        ptr = ptr->next;
    }

    if(flag == 1)
        printf("%d is present at position %d in the SLL\n", element, pos+1);

    else
        printf("%d is not present in the SLL\n", element);
}

void reverse()
{
    struct Node *next, *prev;
    next = NULL;
    prev = NULL;

    while(head != NULL)
    {
        next = head->next;
        prev = head->prev;
        head->next = prev;
        head->prev = next;
        head = next;
    }
    head = prev->prev;

    printf("\nDLL reversed successfully\n");
}

void countNodes()
{
    struct Node *ptr = head;
    int count = 0;

    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    printf("\nNumber of Nodes : %d\n", count);
}

void printData()
{
    struct Node *ptr = head;

    if(ptr == NULL)
        printf("\nDLL is empty\n");

    else
    {
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main(int argc, char argv[])
{
    create();

    char s[10];
    int choice = 0;
    while(choice != 12)
    {
        printf("\nIf you want to perform any operations on created DLL : ");
        scanf("%s", s);

        if(strcmp(s, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. Insert a node at begining\n2. Insert a node at end\n3. Insert a node at given position\n4. Delete a node at begining\n5. Delete a node at end\n6. Delete a node at given position\n7. Delete DLL\n8. Search for an element\n9. Reverse a DLL\n10. Counting the number of nodes\n11. Printing the data\n12. Exit\n");
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