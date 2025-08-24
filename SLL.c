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
void delete_by_val(int);
void find_min_max(void);

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

    int val = 0;
    printf("Enter the value to be deleted: ");
    scanf("%d", &val);
    delete_by_val(val);
    print();

    find_min_max();

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
    struct Node *curr, *prev, *next; 

    curr = head; 
    prev = NULL;

    while(curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
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

void delete_by_val(int val) {
    if(head == NULL) {
        printf("List is empty, nothing to delete\n");
        return; 
    }

    if(head->data == val) {
        struct Node *temp = head;
        head = head->link;
        free(temp);
        printf("Deleted %d\n", val);
        return;
    }

    struct Node *curr = head;
    while(curr->link != NULL && curr->link->data != val) {
        curr = curr->link;
    }

    if(curr->link == NULL) {
        printf("Value %d not found in the list\n", val);
        return;
    }

    struct Node *temp = curr->link;
    curr->link = curr->link->link;
    free(temp);
    printf("Deleted %d\n", val);
}

void find_min_max() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head; 
    int min = temp->data;
    int max = temp->data; 

    while(temp != NULL) {
        if(temp->data < min) {
            min = temp->data;
        }

        if(temp->data > max) {
            max = temp->data; 
        }

        temp = temp->link; 
    }

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
}
