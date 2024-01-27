#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *create();
void preorder(struct Node *);
void inorder(struct Node *);
void postorder(struct Node *);

int main(int argc, char *argv[])
{
    struct Node *root = create();

    printf("\nPreorder Traversal : ");
    preorder(root);

    printf("\n\nInorder Traversal : ");
    inorder(root);

    printf("\n\nPostorder Traversal : ");
    postorder(root);

    printf("\n");

    return 0;
}

struct Node *create()
{
    int choice;

    printf("\nEnter 0 for no node");
    printf("\nEnter 1 for new node\n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    if(choice == 0)
        return NULL;

    else
    {
        struct Node *new = malloc(sizeof(struct Node));
        
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

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    if(root == 0)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if(root == 0)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}