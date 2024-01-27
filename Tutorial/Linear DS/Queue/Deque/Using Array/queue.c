#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 20

int queue_arr[max], n;
int f = -1;
int r = -1;

bool isFull();
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
    printf("\nEnter the size of the queue : ");
    scanf("%d", &n);

    int choice = 0;

    while(choice != 11)
    {
        printf("\nChoose one option from the following menu\n");
        printf("\n1. Insertion at front\n2. Insertion at rear\n3. Deletion at front\n4. Deletion at rear\n5. Queue is full or not\n6. Queue is empty or not\n7. Show the first element\n8. Show the last element\n9. Size of the queue\n10. Show\n11. Exit\n");
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
                if(isFull())
                    printf("\nQueue is full\n");
                else
                    printf("\nQueue is not full\n");
                break;
            case 6:
                if(isEmpty())
                    printf("\nQueue is empty\n");
                else
                    printf("\nQueue is not empty\n");
                break;
            case 7: 
                front();
                break;
            case 8:
                rear();
                break;
            case 9:
                size();
                break;
            case 10:
                show();
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("\nPlease enter the valid choice\n");
        }
    }

    return 0;
}

bool isFull()
{
    if((r+1) % n == f)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if((f == -1) && (r == -1))
        return true;
    else
        return false;
}

void enqueueFront()
{
    if(isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }

    if(isEmpty())
        f = r = 0;

    else if(f == 0)
        f = n-1;

    else
        f--;

    printf("\nEnter the data for this element : ");
    scanf("%d", &queue_arr[f]);

    printf("\nElement inserted successfully\n");
}

void enqueueRear()
{
    if(isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }

    if(isEmpty())
        f = r = 0;

    else
        r = (r+1) % n;

    printf("\nEnter the data for this element : ");
    scanf("%d", &queue_arr[r]);

    printf("\nElement inserted successfully\n");    
}

void dequeueFront()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }

    if(f == r)
        f = r = -1;
    
    else
        f = (f+1) % n;

    printf("\nElement deleted successfully\n");
}

void dequeueRear()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }

    if(f == r)
        f = r = -1;

    else if(r == 0)
        r = n-1;

    else
        r--;

    printf("\nElement deleted successfully\n");
}

void front()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }

    printf("\nFirst element in the queue : %d\n", queue_arr[f]);
}

void rear()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }

    printf("\nlast element in the queue : %d\n", queue_arr[r]);
}

void size()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    int i = f;
    int count = 0;

    while(i != r)
    {
        count++;
        i = (i+1) % n;
    }
    printf("\nNumber of elements in the queue : %d\n", count + 1);
}

void show()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    int i = f;
    while(i != r)
    {
        printf("%d\n", queue_arr[i]);
        i = (i+1) % n;
    }
    printf("%d\n", queue_arr[r]);
}