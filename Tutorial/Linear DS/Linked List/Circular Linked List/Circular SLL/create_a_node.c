#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *link;
};

int main(int argc, char *argv[])
{
    struct Node *tail = malloc(sizeof(struct Node));
    tail->data = 5;
    tail->link = tail;

    return 0;
}