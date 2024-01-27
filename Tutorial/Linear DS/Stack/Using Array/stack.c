#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max 10

int stack_arr[max], n;
int top = -1;

void append(int);
void create();
bool isFull();
void push();
bool isEmpty();
void pop();
void peek();
void size();
void show();

int main(int argc, char *argv[])
{
    printf("Enter the number of elements you want to push into the stack : ");
    scanf("%d", &n);

    create();

    char str[10];
    int choice = 0;
    while(choice != 8)
    {
        printf("\nIf you want to perform any operations : ");
        scanf("%s", str);

        if(strcmp(str, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. push()\n2. pop()\n3. peek()\n4. isFull()\n5. isEmpty\n6. size()\n7. show()\n8. exit()\n");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    peek();
                    break;
                case 4:
                    if(isFull())
                        printf("\nStack is full\n");
                    else
                        printf("\nStack is not full\n");
                    break;
                case 5:
                    if(isEmpty())
                        printf("\nStack is empty\n");
                    else
                        printf("\nStack is not empty\n");
                    break;
                case 6:
                    size();
                    break;
                case 7:
                    show();
                    break;
                case 8:
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
    top++;
    stack_arr[top] = data;
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

bool isFull()
{
    if(top == max-1)
        return true;

    else
        return false;
}

void push()
{
    if(isFull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    printf("\nEnter the data for this element : ");
    scanf("%d", &stack_arr[top]);

    printf("Element pushed successfully\n");
}

bool isEmpty()
{
    if(top == -1)
        return true;

    else
        return false;
}

void pop()
{
    if(isEmpty())
    {
        printf("\nStack Underflow\n");
        return;
    }
    top--;

    printf("\nElement poped successfully\n");
}

void peek()
{
    printf("\nThe Element at the top of the stack : %d\n", stack_arr[top]);
}

void size()
{
    int count = 0, i;
    for(i=top; i>=0; i--)
        count++;

    printf("\nNumber of elements in the stack : %d\n", count);
}

void show()
{
    if(isEmpty())
    {
        printf("\nStack is empty\n");
        return;
    }
    int i;
    for(i=top; i>=0; i--)
    {
        printf("%d\n", stack_arr[i]);
    }
}