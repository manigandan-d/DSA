#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;

void append(int);
void create();
void push();
void pop();
void peek();
void size();
void show();

int main(int argc, char *argv[])
{
    create();

    int choice = 0;
    char str[10];

    while(choice != 6)
    {
        printf("\nIf you want to perform any operations : ");
        scanf("%s", str);

        if(strcmp(str, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. push()\n2. pop()\n3. peek()\n4. size()\n5. show()\n6. exit()\n");
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
                    size();
                    break;
                case 5:
                    show();
                    break;
                case 6:
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
    struct Node *new = malloc(sizeof(struct Node));
    if(new == NULL)
        printf("\nStack Overflow\n");

    else
    {
        new->data = data;
        new->link = head;
        head = new;
    }
}

void create()
{
    int data, i, n;
    printf("Enter the number of elements you want to push onto the stack : ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Enter the data for the element %d : ", i);
        scanf("%d", &data);
        append(data);
    }
}

void push()
{
    struct Node *new = malloc(sizeof(struct Node));

    if(new == NULL)
        printf("\nStack Overflow\n");

    else
    {
        printf("\nEnter the data for this element : ");
        scanf("%d", &new->data);
        new->link = head;
        head = new;

        printf("Element pushed successfully\n");
    }
}

void pop()
{
    struct Node *temp;

    if(head == NULL)
        printf("\nStack Underflow\n");

    else
    {
        temp = head->link;
        free(head);
        head = temp;

        printf("\nElement poped successfully\n");
    }
}

void peek()
{
    printf("\nElement at the top of the stack : %d\n", head->data);
}

void size()
{
    int count = 0;
    struct Node *ptr = head;

    if(ptr == NULL)
        printf("\nStack is empty\n");

    else
    {
        while(ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
    }

    printf("\nNumber of elements in the stack : %d\n", count);
}

void show()
{
    struct Node *ptr = head;
    if(ptr == NULL)
        printf("\nStack is empty\n");

    else
    {
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
    }
}