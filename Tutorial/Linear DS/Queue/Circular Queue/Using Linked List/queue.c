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

bool isEmpty();
void enqueue();
void dequeue();
void front();
void rear();
void size();
void show();

int main(int argc, char *argv[])
{
    int choice = 0;
    char str[10];

    while(choice != 7)
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

    return 0;
}

bool isEmpty()
{
    if((head == NULL) && (tail == NULL))
        return true;
    else 
        return false;
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

    if(isEmpty())
    {
        new->link = new;
        head = tail = new;
    }
    else
    {
        new->link = head;
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
        free(head);
        head = tail = NULL;
    }
    else
    {
        struct Node *temp = head->link;
        free(head);
        head = temp;
        tail->link = head;
    }

    printf("\nElement deleted successfully\n");
}

void front()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nFirst element in the queue : %d\n", head->data);
}

void rear()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nLast element in the queue : %d\n", tail->data);
}

void size()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    struct Node *ptr = head;
    int count = 0;
    do
    {
        count++;
        ptr = ptr->link;
    } while (ptr != head);
    
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
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    } while (ptr != head);
    
}