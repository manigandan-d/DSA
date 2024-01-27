#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
    int height;
};

int max(int, int);
int height(struct Node *node);
int getBalance(struct Node *node);
struct Node *llr(struct Node *z);
struct Node *rrr(struct Node *x);
struct Node *create(int);
struct Node *insert(struct Node *root, int data);
int findMin(struct Node *);
struct Node *delete(struct Node *root, int data);
void preorder(struct Node *);
void inorder (struct Node *);
void postorder (struct Node *);
int findMax(struct Node *);
void search(struct Node *, int);

int main(int argc, char *argv[])
{
    struct Node *root = NULL;
    int n, i, a;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    printf("\n");

    for(i=0; i<n; i++)
    {
        printf("Enter the data value : ");
        scanf("%d", &a);
        root = insert(root, a);
    }

    char s[MAX];
    int choice = 0;
    while(choice != 12)
    {
        printf("\nIf you want to perform any operations on created AVL : ");
        scanf("%s", s);

        if(strcmp(s, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. Insertion\n2. Deletion\n3. Preorder Traversal\n4. Inorder Traversal\n5. Postorder Traversal\n6. Find the Minimum Value\n7. Find the Maximum Value\n8. Searching\n");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    printf("\nEnter the data to insert : ");
                    scanf("%d", &a);
                    root = insert(root, a);
                    printf("Element inserted successfully\n");
                    break;
                case 2:
                    printf("\nEnter the data to delete : ");
                    scanf("%d", &a);
                    root = delete(root, a);
                    printf("Element deleted successfully\n");
                    break;
                case 3:
                    printf("\nPreorder Traversal : ");
                    preorder(root);
                    printf("\n");
                    break;
                case 4:
                    printf("\nInorder Traversal : ");
                    inorder(root);
                    printf("\n");
                    break;
                case 5:
                    printf("\nPostorder Traversal : ");
                    postorder(root);
                    printf("\n");
                    break;
                case 6:
                    printf("\nMinimum Value : %d\n", findMin(root));
                    break;
                case 7:
                    printf("\nMaximum Value : %d\n", findMax(root));
                    break;
                case 8:
                    printf("\nEnter the data to search : ");
                    scanf("%d", &a);
                    search(root, a);
                    break;
                default:
                    printf("\nPlease Enter the valid choice\n");
            }
        }
        else
            break;
    }

    return 0;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int height(struct Node *node)
{
    if(node == NULL)
        return 0;
    
    return node->height;
}

int getBalance(struct Node *node)
{
    if(node == NULL)
        return 0;
    
    return (height(node->left) - height(node->right));
}

struct Node *llr(struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = (max(height(x->left), height(x->right)) + 1);
    y->height = (max(height(y->left), height(y->right)) + 1);

    return y;
}

struct Node *rrr(struct Node *z)
{
    struct Node *y = z->left;
    z->left = y->right;
    y->right = z;

    z->height = (max(height(z->left), height(z->right)) + 1);
    y->height = (max(height(y->left), height(y->right)) + 1);

    return y;
}

struct Node *create(int data)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->left = NULL;
    new->data = data;
    new->right = NULL;
    new->height = 1;

    return new;
}

struct Node *insert(struct Node *root, int data)
{
    if(root == NULL)
    {
        return create(data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    root->height = (max(height(root->left), height(root->right))) + 1;

    int bf = getBalance(root);

    if(bf < -1)
    {
        if(data > root->right->data)
        {
            return llr(root);
        }
        else
        {
            root->right = rrr(root->right);
            return llr(root);
        }
    }

    if(bf > 1)
    {
        if(data < root->left->data)
        {
            return rrr(root);
        }
        else
        {
            root->left = llr(root->left);
            return rrr(root);
        }
    }

    return root;
}

int findMin(struct Node *ptr)
{
    while(ptr->left != NULL)
    {
        ptr = ptr->left;
    }

    return ptr->data;
}

struct Node *delete(struct Node *root, int data)
{
    struct Node *ptr = root;
    struct Node *par = NULL;

    while((ptr!=NULL) && (data != ptr->data))
    {
        par = ptr;
        if(data < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if((ptr->left == NULL) && (ptr->right == NULL))
    {
        if(ptr != NULL)
        {
            if(ptr == par->left)
                par->left = NULL;
            else
                par->right = NULL;
        }
        else 
            root = NULL;

        free(ptr);
    }

    else if(ptr->left && ptr->right)
    {
        int data = findMin(ptr->right);
        root = delete(root, data);
        ptr->data = data;
    }

    else
    {
        struct Node *child = (ptr->left)?ptr->left:ptr->right;
        if(ptr != NULL)
        {
            if(ptr == par->left)
                par->left = child;
            else
                par->right = child;
        }
        else 
            root = child; 

        free(ptr);
    }

    root->height = (max(height(root->left), height(root->right))) + 1;

    int bf = getBalance(root);

    if(bf < -1)
    {
        if(getBalance(root->right) <= 0)
            return llr(root);
        else
        {
            root->right = rrr(root->right);
            return llr(root);
        }
    }

    if(bf > 1)
    {
        if(getBalance(root->left) >= 0)
            return rrr(root);
        else
        {
            root->left = llr(root->left);
            return rrr(root);
        }
    }

    return root;
}

void preorder(struct Node *root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int findMax(struct Node *ptr)
{
    while(ptr->right != NULL)
    {
        ptr = ptr->right;
    }

    return ptr->data;
}

void search(struct Node *root, int data)
{
    struct Node *ptr = root;
    struct Node *par = NULL;

    while((ptr != NULL) && (data != ptr->data))
    {
        par = ptr;
        if(data < ptr->data)
        {
            ptr = ptr->left;
        }
        else 
        {
            ptr = ptr->right;
        }
    }

    if(ptr != NULL)
        printf("%d is present in the AVL\n", data);
    
    else
        printf("%d is not present in the AVL\n", data);
}