#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Node 
{
	struct Node *left;
	int data;
	struct Node *right;
};

struct Node *zig(struct Node *);
struct Node *zag(struct Node *);
struct Node *splay(struct Node *, int);
struct Node *create(int);
struct Node *insert(struct Node *, int);
struct Node *delete(struct Node *, int);
struct Node *search(struct Node *, int);
void preorder(struct Node *);
void inorder(struct Node *);
void postorder(struct Node *);

int main()
{
	struct Node *root = NULL;

	int n, i, a;

	printf("\nEnter the number of elements : ");
	scanf("%d", &n);
	printf("\n");

	for(i=0; i<n; i++)
	{
		printf("Enter the data : ");
		scanf("%d", &a);

		root = insert(root, a);
	}

	char s[MAX];

    int choice = 0;

    while(choice != 7)
    {
        printf("\nIf you want to perform any operations on the created Splay Tree : ");
        scanf("%s", s);

        if(strcmp(s, "yes") == 0)
        {
            printf("\nChoose one option from the following menu\n");
            printf("\n1. Insertion\n2. Deletion\n3. Searching\n4. Preorder Traversal\n5. Inorder Traversal\n6. Postorder Traversal\n7. Exit\n");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:

                    printf("\nEnter the data to insert : ");
                    scanf("%d", &a);

                    root = insert(root, a);

                    printf("\nElement inserted successfully\n");

                    break;

                case 2:

                    printf("\nEnter the data to delete : ");
                    scanf("%d", &a);

                    root = delete(root, a);

                    printf("\nElement deleted successfully\n");

                    break;

                case 3:

                    printf("\nEnter the data to search : ");
                    scanf("%d", &a);

                    root = search(root, a);

                    break;

                case 4:

                    printf("\nPreorder Traversal : ");

                    preorder(root);

                    printf("\n");

                    break;

                case 5:

                    printf("\nInorder Traversal : ");

                    inorder(root);

                    printf("\n");

                    break;

                case 6:

                    printf("\nPostorder Traversal : ");

                    postorder(root);

                    printf("\n");

                    break;

				case 7:

					exit(0);

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

struct Node *zig(struct Node *z)
{
	struct Node *y = z->left;
	z->left = y->right;
	y->right = z;

	return y;
}

struct Node *zag(struct Node *x)
{
	struct Node *y = x->right;
	x->right = y->left;
	y->left = x;

	return y;
}

struct Node *splay(struct Node *root, int data)
{
	if((root == NULL) || (data == root->data))
		return root;

	if(data < root->data)
	{
		if(root->left == NULL)
			return root;
		
		if(data < root->left->data)
		{
			root->left->left = splay(root->left->left, data);
			root = zig(root);
		}

		else if(data > root->left->data)
		{
			root->left->right = splay(root->left->right, data);

			if(root->left->right != NULL)
				root->left = zag(root->left);
		}

		return (root->left == NULL) ? root : zig(root);
	}

	else
	{
		if(root->right == NULL)
			return root;
		
		if(data < root->right->data)
		{
			root->right->left = splay(root->right->left, data);

			if(root->right->left != NULL)
				root->right = zig(root->right);
		}

		else if(data > root->right->data)
		{
			root->right->right = splay(root->right->right, data);
			root = zag(root);
		}

		return (root->right == NULL) ? root : zag(root);
	}
}

struct Node *create(int data)
{
	struct Node *new = malloc(sizeof(struct Node));
	new->left = NULL;
	new->data = data;
	new->right = NULL;

	return new;
}

struct Node *insert(struct Node *root, int data)
{
	if(root == NULL)
		return create(data);

	root = splay(root, data);

	if(data == root->data)
		return root;

	struct Node *new = create(data);

	if(data < root->data)
	{
		new->right = root;
		new->left = root->left;
		root->left = NULL;
	}

	else
	{
		new->left = root;
		new->right = root->right;
		root->right = NULL;
	}

	return new;
}

struct Node *delete(struct Node *root, int data)
{
	if(root == NULL)
		return root;

	root = splay(root, data);

	if(data != root->data)
		return root;

	struct Node *temp = NULL;

	if(root->left == NULL)
	{
		temp = root;
		root = root->right;
	}

	else
	{
		temp = root;
		root = splay(root->left, data);
		root->right = temp->right;
	}

	free(temp);

	return root;
}

struct Node *search(struct Node *root, int data)
{
	root = splay(root, data);

	if(data == root->data)
		printf("Data is present in the Tree\n");

	else 
		printf("Data is not present in the Tree\n");

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