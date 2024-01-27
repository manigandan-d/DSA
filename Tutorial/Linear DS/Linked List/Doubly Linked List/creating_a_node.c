#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int main(int argc, char *argv[])
{
    struct Node *head = malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = 5;
    head->next = NULL;

    return 0;
}