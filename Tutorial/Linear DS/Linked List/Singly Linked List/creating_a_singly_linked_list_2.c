#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

int main(int argc, char *argv[])
{
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 5;
    head->link = NULL;

    struct Node *current = malloc(sizeof(struct Node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct Node));
    current->data = 15;
    current->link = NULL;
    head->link->link = current;

    return 0;
}