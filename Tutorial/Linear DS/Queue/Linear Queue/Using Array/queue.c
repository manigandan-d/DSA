#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define max 10

int queue_arr[max], n;
int f = -1, r = -1;

void append(int);
void create();
bool isFull();
void enqueue();
bool isEmpty();
void dequeue();
void front();
void rear();
void size();
void show();

int main(int argc, char *argv[])
{
    printf("Enter the number of elements you want to add in the queue : ");
    scanf("%d", &n);

    create();

    int choice = 0;
    char str[max];
    while(choice != 9)
    {
        printf("\nIf you want to perform any operations : ");
        scanf("%s", str);
        if(strcmp(str, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. enqueue()\n2. dequeue()\n3. isFull()\n4. isEmpty()\n5. front()\n6. rear()\n7. size()\n8. show()\n9. exit()\n");
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
                    printf("\nPlease enter the valid choice\n");
            }
        }
        else
            break;
    }

    return 0;
}

void append(int data)
{
    if((f == -1) && (r == -1))
    {
        f = 0;
        r = 0;
    }
    else 
    {
        r++;
    }
    queue_arr[r] = data;
}

void create()
{
    int data, i;
    for(i=1; i<=n; i++)
    {
        printf("Enter the data for the element %d : ", i);
        scanf("%d", &data);
        append(data);
    }
}

bool isFull()
{
    if(r == (max-1))
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
    if((f == -1) && (r == -1))
    {
        f = 0;
        r = 0;
    }
    else
    {
        r++;
    }
    printf("\nEnter the data : ");
    scanf("%d", &queue_arr[r]);

    printf("\nElement inserted successfully\n");
}

bool isEmpty()
{
    if((f == -1) && (r == -1))
        return true;

    else
        return false;
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
        f++;
    }

    printf("\nElement deleted successfully\n");
}

void front()
{
    printf("\nElement at the top of the queue : %d\n", queue_arr[f]);
}

void rear()
{
    printf("\nElement at the end of the queue : %d\n", queue_arr[r]);
}

void size()
{
    int i, count = 0;
    if(isEmpty())
        printf("\nQueue is empty\n");

    else
    {
        for(i=f; i<=r; i++)
        {
            count++;
        }
    }

    printf("\nNumber of elements in the queue : %d\n", count);
}

void show()
{
    int i;
    if(isEmpty())
        printf("\nQueue is empty\n");

    else
    {
        for(i=f; i<=r; i++)
        {
            printf("%d\n", queue_arr[i]);
        }
    }
}