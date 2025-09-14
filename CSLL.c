#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node *link;
};

struct Node *head = NULL; 

void insert_at_end();
void insert_at_beg();
int length();
void print_list();
void delete_from_beg();
void delete_from_end();

int main() {
    insert_at_end();
    insert_at_end();
    insert_at_end();

    print_list();
    printf("Length: %d\n", length());

    delete_from_beg();

    print_list();
    printf("Length: %d\n", length());

    delete_from_end();

    print_list();
    printf("Length: %d\n", length());

    return 0;
}

void insert_at_end() {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the value of node to insert at end: ");
    scanf("%d", &new->data);

    new->link = new;

    if(head == NULL) {
        head = new;
        return;
    }

    struct Node *temp = head; 

    while(temp->link != head) {
        temp = temp->link;
    }

    temp->link = new; 
    new->link = head; 
}

void insert_at_beg() {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    
    printf("Enter the value of node to insert at beginning: ");
    scanf("%d", &new->data);

    new->link = new; 

    if(head == NULL) {
        head = new; 
        return; 
    }

    struct Node *temp = head; 

    while(temp->link != head) {
        temp = temp->link;
    }

    temp->link = new;
    new->link = head; 
    head = new;
}

int length() {
    if(head == NULL) {
        return 0; 
    }

    int count = 0;
    struct Node *temp = head; 

    do {
        count++;
        temp = temp->link;
    }while(temp != head);

    return count; 
}

void print_list() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head; 

    printf("CSLL: ");

    do {
        printf("%d ", temp->data);
        temp = temp->link;
    }while(temp != head);

    printf("\n");
}

void delete_from_beg() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head == head->link) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while(temp->link != head) {
        temp = temp->link;
    }

    temp->link = head->link;
    free(head);
    head = temp->link;
}

void delete_from_end() {
    if(head == NULL) {
        printf("List is empty\n");
        return; 
    }

    if(head == head->link) {
        free(head);
        head = NULL;
        return; 
    }

    struct Node *curr = head;
    struct Node *prev = NULL; 

    while(curr->link != head) {
        prev = curr; 
        curr = curr->link;
    }

    prev->link = head;
    free(curr);
}
