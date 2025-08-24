#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node *link; 
};

struct Node *head = NULL;

void append(void);
void insert_at_beg(void);
int length(void);
void print(void);
void insert_after_pos(void);
void delete_at_pos(void);
void reverse(void);
void print_forward_reverse(struct Node *);

int main() {
    append();
    append();
    append();

    insert_at_beg();
    insert_at_beg();

    insert_after_pos();

    delete_at_pos();

    printf("Length of the list: %d\n", length());

    print();

    reverse();
    print();

    printf("Print forward and reverse order: ");
    print_forward_reverse(head);
    printf("\n");

    return 0;
}

void append() {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the value of node: ");
    scanf("%d", &new->data);

    new->link = NULL;

    if(head == NULL) {
        head = new;
    }

    else {
        struct Node *ptr = head; 

        while(ptr->link != NULL) {
            ptr = ptr->link;
        }

        ptr->link = new; 
    }
}

void insert_at_beg() {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the value of node: ");
    scanf("%d", &new->data);

    new->link = head;
    head = new;
}

int length() {
    int count = 0;
    struct Node *ptr = head; 

    while(ptr != NULL) {
        count++;
        ptr = ptr->link;
    }

    return count; 
}

void print() {
    struct Node *ptr = head; 

    if(ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Elements: ");

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    printf("\n");
}

void insert_after_pos() {
    int pos, len, index = 1; 
    struct Node *ptr, *new;

    printf("Enter the position: ");
    scanf("%d", &pos);

    len = length();

    if(len < pos) {
        printf("Invalid position\n");
        return; 
    }

    ptr = head; 

    while(index < pos) {
        index++;
        ptr = ptr->link;
    }

    new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value of node: ");
    scanf("%d", &new->data);

    new->link = ptr->link;
    ptr->link = new; 
}

void delete_at_pos() {
    int pos, len, index = 1;
    struct Node *temp, *prev; 

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    len = length();

    if(len < pos || pos < 1) {
        printf("Invalid position\n");
        return; 
    }

    if(pos == 1) {
        temp = head; 
        head = head->link;
        free(temp);
        printf("Node at position 1 deleted\n");
        return;
    }

    temp = head; 

    while(index < pos) {
        index++;
        prev = temp; 
        temp = temp->link;
    }

    prev->link = temp->link;
    free(temp);

    printf("Node at position %d deleted\n", pos);
}

void reverse() {
    struct Node *cur, *prev, *next; 

    cur = head; 
    prev = NULL;

    while(cur != NULL) {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }

    head = prev;

    printf("Reversed\n");
}

void print_forward_reverse(struct Node *node) {
    if(node == NULL) 
        return; 

    printf("%d ", node->data);
    print_forward_reverse(node->link);
    printf("%d ", node->data);
}
