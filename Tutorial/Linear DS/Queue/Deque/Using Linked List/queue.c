#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

bool isEmpty();
void enqueueFront();
void enqueueRear();
void dequeueFront();
void dequeueRear();
void front();
void rear();
void size();
void show();

int main(int argc, char *argv[])
{
    int choice = 0;
    printf("\nQUEUE OPERATIONS\n");
    
    while(choice != 11)
    {
        printf("\nChoose one option from the following menu\n");
        printf("\n1. Insertion at front\n2. Insertion at rear\n3. Deletion at front\n4. Deletion at rear\n5. Show the first element\n6. Show the last element\n7. Size of the queue\n8. Show\n9. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueueFront();
                break;
            case 2:
                enqueueRear();
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                front();
                break;
            case 6:
                rear();
                break;
            case 7:
                size();
                break;
            case 8:
                show();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\nPlease enter the valid choice\n");
                break;
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

void enqueueFront()
{
    struct Node *new = malloc(sizeof(struct Node));
    if(new == NULL)
    {
        printf("\nQueue Overflow\n");
        return;
    }

    new->prev = NULL;
    printf("\nEnter data for this element : ");
    scanf("%d", &new->data);

    if(isEmpty())
    {
        new->next = NULL;
        head = new;
        tail = new;
    }

    else
    {
        new->next = head;
        head->prev = new;
        head = new;
    }

    printf("\nElement inserted successfully\n");
}

void enqueueRear()
{
    struct Node *new = malloc(sizeof(struct Node));
    if(new == NULL)
    {
        printf("\nQueue Overflow\n");
        return;
    }

    new->next = NULL;
    printf("\nEnter data for this element : ");
    scanf("%d", &new->data);

    if(isEmpty())
    {
        new->prev = NULL;
        head = new;
        tail = new;
    }

    else
    {
        new->prev = tail;
        tail->next = new;
        tail = new;
    }

    printf("\nElement inserted successfully\n");
}

void dequeueFront()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }

    if(head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }

    else
    {
        struct Node *temp = head->next;
        free(head);
        temp->prev = NULL;
        head = temp;
    }

    printf("\nElement deleted successfully\n");
}

void dequeueRear()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }

    if(head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }

    else
    {
        struct Node *temp = tail->prev;
        free(tail);
        temp->next = NULL;
        tail = temp;
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

    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
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
        ptr = ptr->next;
    }
}