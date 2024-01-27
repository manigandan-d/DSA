#include <stdio.h>
#include <stdlib.h>

enum Colour {black, red};

struct Node 
{
    struct Node *par;
    struct Node *left;
    int data;
    struct Node *right;
    int colour;
};

struct Node *root = NULL;

void llr(struct Node *);
void rrr(struct Node *);
struct Node *insert(struct Node *, struct Node *);
void fixUp(struct Node *, struct Node *);
void preorder(struct Node *);
void inorder(struct Node *);
void postorder(struct Node *);

int main()
{
    int n, i, a;
    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    printf("\n");

    for(i=0; i<n; i++)
    {
        printf("Enter the data value : ");
        scanf("%d", &a);

        struct Node *new = malloc(sizeof(struct Node));

        new->par = NULL;
        new->left = NULL;
        new->data = a;
        new->right = NULL;
        new->colour = red;

        root = insert(root, new);

        fixUp(root, new);
    }

    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}

void llr(struct Node *x)
{
    struct Node *y = x->right;
    x->right = y->left;

    if(y->left != NULL)
        y->left->par = x;

	y->par = x->par;

    if(x->par == NULL)
        root = y;
    
    else if(x == x->par->left)
        x->par->left = y;

    else
        x->par->right = y;

	y->left = x;
    x->par = y;
}

void rrr(struct Node *z)
{
    struct Node *y = z->left;
    z->left = y->right;

	if(y->right != NULL) 
        y->right->par = z;

	y->par = z->par;
	
    if(z->par == NULL)
        root = y;

    else if(z == z->par->left)
        z->par->left = y;

    else
        z->par->right = y;

	y->right = z;
    z->par = y;
}

struct Node *insert(struct Node* root, struct Node* new)
{

	if(root == NULL)
		return new;

	if(new->data < root->data)
	{
		root->left = insert(root->left, new);
		root->left->par = root;
	}
	else
	{
		root->right = insert(root->right, new);
		root->right->par = root;
	}

	return root;
}

void fixUp(struct Node *root, struct Node *new)
{
    struct Node *p = NULL;
    struct Node *gp = NULL;
    struct Node *parSib = NULL;

	while((new->par->colour != black) && (new != root) && (new->colour != black))
	{
        p = new->par;
        gp = new->par->par;

		if(p == gp->left)
        {
            parSib = gp->right;

            if((parSib->colour == black) || (parSib == NULL))
            {
                if(new == p->right)
                {
                    llr(p);
                    new = p;
                    p = new->par;
                }

                rrr(gp);

                int temp = p->colour;
                p->colour = gp->colour;
                gp->colour = temp;
                new = p;
            }

            else
            {
                gp->colour = red;
                p->colour = black;
                parSib->colour = black;
                new = gp; 
            }
        }
    
		else
        {
            parSib = gp->left;

            if((parSib->colour == black) || (parSib == NULL))
            {
                if(new == p->left)
                {
                    rrr(p);
                    new = p;
                    p = new->par;
                }

                llr(gp);

                int temp = p->colour;
                p->colour = gp->colour;
                gp->colour = temp;
                new = p;
            }

            else
            {
                gp->colour = red;
                p->colour = black;
                parSib->colour = black;
                new = gp; 
            }
        }
	}
	root->colour = black;
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