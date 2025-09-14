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
    insert_at_end();
    insert_at_end();

    print_list();
    printf("Length: %d\n", length());

    insert_at_pos();
    print_list();
    printf("Length: %d\n", length());

    insert_at_pos();
    print_list();
    printf("Length: %d\n", length());

    insert_at_pos();
    print_list();
    printf("Length: %d\n", length());

    delete_at_beg();
    print_list();
    printf("Length: %d\n", length());

    delete_at_end();
    print_list();
    printf("Length: %d\n", length());

    delete_at_pos();
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
    int pos, len, index = 1; 

    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    len = length();

    if(pos < 1 || pos > len+1) {
        printf("Invalid position\n");
        return; 
    }

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->prev = NULL;
    new->next = NULL;

    printf("Enter the value: ");
    scanf("%d", &new->data);

    if(pos == 1) {
        if(head != NULL) {
            head->prev = new; 
            new->next = head;
        }

        head = new; 

        return; 
    }

    struct Node *temp = head; 

    while(index < pos-1) {
        index++;
        temp = temp->next; 
    }

    if(temp->next != NULL) {
        new->next = temp->next;
        temp->next->prev = new; 
    }

    new->prev = temp;
    temp->next = new; 
}

void delete_at_beg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (head->next == NULL) {  
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

void delete_at_pos() {
    int pos, len, index = 1;

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    len = length();

    if (pos < 1 || pos > len) {
        printf("Invalid position\n");
        return;
    }

    struct Node *temp = head; 

    if (pos == 1) {
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(temp);

        return;
    }

    temp = head;

    while (index < pos) {
        index++;
        temp = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
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
