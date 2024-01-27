#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 50

int queue_arr[max], n;
int f = -1, r = -1;

bool isFull();
bool isEmpty();
void enqueue();
void dequeue();
void front();
void rear();
void size();
void show();

int main(int argc, char *argv[])
{
    printf("\nEnter the number of elements you want to add in the queue : ");
    scanf("%d", &n);
    
    printf("\nQUEUE OPERATIONS\n");

    printf("\nChoose one option from the following menu\n");
    
    int choice = 0;
    while(choice != 9)
    {
        printf("\n1. Insert an element\n2. Delete an element\n3. Queue is full or not\n4. Queue is empty or not\n5. Show the first element\n6. Show the last element\n7. Size of the Queue\n8. Show\n9. Exit\n");
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
                if(isFull())
                    printf("\nQueue is full\n");
                else
                    printf("\nQueue is not full\n");

                break;
            
            case 4:
                if(isEmpty())
                    printf("\nQueue is empty\n");
                else
                    printf("\nQueue is not empty\n");
                    
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
                printf("\nPlease Enter the valid choice\n");
        }
    }

    return 0;
}

bool isFull()
{
    if((r+1)%n == f)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if((r == -1) && (f == -1))
        return true;
    else
        return false;
}

void enqueue()
{
    if(isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if(isEmpty())
    {
        f = 0;
        r = 0;
    }
    else
    {
        r = (r+1) % n;
    }
    printf("\nEnter the data for this element : ");
    scanf("%d", &queue_arr[r]);

    printf("\nElement inserted successfully\n");
}

void dequeue()
{
    if(isEmpty())
    {
        printf("\nQueue Underflow\n");
        return;
    }
    if(f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f+1) % n;
    }

    printf("\nElement deleted successfully\n");
}

void front()
{
    printf("\nFirst element in the queue : %d\n", queue_arr[f]);
}

void rear()
{
    printf("\nLast element in the queue : %d\n", queue_arr[r]);
}

void size()
{
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    int i, count = 0;

    if(f <= r)
    {
        for(i=f; i<=r; i++)
            count++;
    }
    else
    {
        for(i=f; i<n; i++)
            count++;

        for(i=0; i<=r; i++)
            count++;
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

    int i;

    if(f <= r)
    {
        for(i=f; i<=r; i++)
            printf("%d\n", queue_arr[i]);
    }
    else
    {
        for(i=f; i<n; i++)
            printf("%d\n", queue_arr[i]);

        for(i=0; i<=r; i++)
            printf("%d\n", queue_arr[i]);
    }
}