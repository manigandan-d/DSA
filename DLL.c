#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data; 
    struct Node *next; 
};

struct Node *head = NULL;

void print_list();
int length();
void insert_at_beg();
void insert_at_end();
void insert_at_pos();
void delete_at_beg();
void delete_at_end();
void delete_at_pos();

int main() {
    insert_at_beg();
    insert_at_end();

    print_list();
    printf("Length: %d\n", length());

    return 0;
}

void insert_at_beg() {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->prev = NULL;
    new->next = NULL;
    
    printf("Enter the value of node to insert at beginning: ");
    scanf("%d", &new->data);

    if(head == NULL) {
        head = new;
        return; 
    }

    new->next = head;
    head->prev = new;
    head = new; 
}

void insert_at_end() {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->prev = NULL;
    new->next = NULL;
    
    printf("Enter the value of node to insert at end: ");
    scanf("%d", &new->data);

    if(head == NULL) {
        head = new;
        return; 
    }

    struct Node *temp = head; 

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new; 
    new->prev = temp; 
}

void insert_at_pos() {

}

void delete_at_beg() {

}

void delete_at_end() {

}

void delete_at_pos() {
    
}

void print_list() {
    if(head == NULL) {
        printf("List is empty\n");
        return; 
    }

    struct Node *temp = head;

    printf("DLL: ");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int length() {
    int count = 0;

    if(head == NULL) {
        printf("List is empty\n");
        return count; 
    }

    struct Node *temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count; 
}
