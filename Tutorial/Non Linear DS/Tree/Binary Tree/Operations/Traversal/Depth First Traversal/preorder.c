#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *create()
{
    struct Node *new = malloc(sizeof(struct Node));
    int choice;

    printf("\nEnter 0 for no node\n");
    printf("Enter 1 for new node\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    if(choice == 0)
        return NULL;

    else
    {
        printf("\nEnter the data : ");
        scanf("%d", &new->data);

        printf("\nEnter the left child node of %d\n", new->data);
        new->left = create();

        printf("\nEnter the right child node of %d\n", new->data);
        new->right = create();

        return new;
    }
}

void preorder(struct Node *root)
{
    if(root == 0)
        return;

    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, char *argv[])
{
    struct Node *root = create();

    preorder(root);

    return 0;
}