#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;

void empInsert(int);
void begInsert();
void endInsert();
void append(int);
void posInsert();
void create();
void begDelete();
void endDelete();
void posDelete();
void delete();
void search();
void reverse();
void countNodes();
void printData();

int main(int argc, char argv[])
{
    create();

    char s[10];
    int choice = 0;
    while(choice != 12)
    {
        printf("\nIf you want to perform any operations on created SLL : ");
        scanf("%s", s);

        if(strcmp(s, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. Insert a node at begining\n2. Insert a node at end\n3. Insert a node at given position\n4. Delete a node at begining\n5. Delete a node at end\n6. Delete a node at given position\n7. Delete SLL\n8. Search for an element\n9. Reverse a SLL\n10. Counting the number of nodes\n11. Printing the data\n12. Exit\n");
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

void empInsert(int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = NULL;
    head = new;
}

void begInsert()
{
    int data;
    printf("\nEnter the data for this node : ");
    scanf("%d", &data);
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->link = head;
    head = new;

    printf("Node inserted successfully\n");
}

void endInsert()
{
    int data;
    printf("\nEnter the data for this node : ");
    scanf("%d", &data);

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

    printf("Node inserted successfully\n");
}

void append(int data)
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

void posInsert()
{
    int pos, data;
    printf("\nEnter the position where you want to insert a node : ");
    scanf("%d", &pos);
    printf("Enter the data for this node : ");
    scanf("%d", &data);

    struct Node *ptr, *new;
    ptr = head;
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

    printf("Node inserted successfully\n");
}

void create()
{
    int data, n, i;
    printf("Enter the number of node you want : ");
    scanf("%d", &n);
    
    if(n == 0)
        head = NULL;

    else{
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
    struct Node *temp = head;
    head = head->link;
    free(temp);
    temp = NULL;

    printf("\nNode at the begining deleted successfully\n");
}

void endDelete()
{
    struct Node *prev, *cur;
    prev = head;
    cur = head;

    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    free(cur);
    cur = NULL;

    printf("\nNode at the end deleted successfully\n");
}

void posDelete()
{
    int pos;
    printf("\nEnter the position where you want to delete the node : ");
    scanf("%d", &pos);
    int p = pos;

    struct Node *cur, *prev;
    cur = head;
    prev = head;

    while(pos != 1)
    {
        prev = cur;
        cur = cur->link;
        pos--;
    }
    prev->link = cur->link;
    free(cur);
    cur = NULL;

    printf("Node at the position %d deleted successfully\n", p);
}

void delete()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }

    printf("\nSLL deleted successfully\n");
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
        ptr = ptr->link;
    }

    if(flag == 1)
        printf("%d is present at position %d in the SLL\n", element, pos+1);

    else
        printf("%d is not present in the SLL\n", element);
}

void reverse()
{
    struct Node *prev, *next;
    prev = NULL;
    next = NULL;

    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;

    printf("\nSLL reversed successfully\n");
}

void countNodes()
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

    printf("\nNumber of Nodes : %d\n", count);
}

void printData()
{
    struct Node *ptr = head;
    
    if(ptr == NULL)
        printf("\nSLL is empty\n");
    
    else
    {
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
    }
}