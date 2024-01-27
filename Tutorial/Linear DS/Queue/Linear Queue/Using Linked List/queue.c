#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;
struct Node *tail = NULL;

int n;

bool isEmpty();
void append(int);
void create();
void enqueue();
void dequeue();
void front();
void rear();
void size();
void show();

int main(int argc, char *argv[])
{
    printf("\nNumber of elements you want to add in the queue : ");
    scanf("%d", &n);

    create();

    char str[10];
    int choice = 0;

    while(choice != 7)
    {
        printf("\nIf you want to perform any operations : ");
        scanf("%s", str);

        if(strcmp(str, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. Insert an element\n2. Delete an element\n3. Show the first element\n4. Show the last element\n5. Size of the Queue\n6. Show\n7. Exit\n");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    enqueue();
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    front();
                    break;
                case 4:
                    rear();
                    break;
                case 5: 
                    size();
                    break;
                case 6:
                    show();
                    break;
                case 7: 
                    exit(0);
                    break;
                default:
                    printf("\nPlease enter the valid choice\n");
            }
        }
        else
            break;
    }

    return 0;
}

bool isEmpty()
{
    if((head == NULL) && (tail == NULL))
        return true;
    else 
        return false;
}

void append(int data)
{
    struct Node *new = malloc(sizeof(struct Node));

    if(new == NULL)
    {
        printf("\nQueue Overflow\n");
        return;
    }

    new->data = data;
    new->link = NULL;

    if(isEmpty())
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->link = new;
        tail = new;
    }
}

void create()
{
    int i, data;

    for(i=1; i<=n; i++)
    {
        printf("Enter the data for the element %d : ", i);
        scanf("%d", &data);
        append(data);
    }
}

void enqueue()
{
    struct Node *new = malloc(sizeof(struct Node));

    if(new == NULL)
    {
        printf("\nQueue Overflow\n");
        return;
    }

    printf("\nEnter the data for this element : ");
    scanf("%d", &new->data);
    new->link = NULL;

    if(isEmpty())
    {
        head = new;
        tail = new;
    }
    else
    {
        tail->link = new;
        tail = new;
    }

    printf("\nElement inserted successfully\n");
}

void dequeue()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }
    if(head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct Node *temp = head->link;
        free(head);
        head = temp;
    }

    printf("\nElement deleted successfully\n");
}

void front()
{
    printf("\nFirst element in the queue : %d\n", head->data);
}

void rear()
{
    printf("\nLast element in the queue : %d\n", tail->data);
}

void size()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    int count = 0;
    struct Node *ptr = head;

    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }

    printf("\nNumber of elements in the queue : %d\n", count);
}

void show()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    struct Node *ptr = head;

    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}