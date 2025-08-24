#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data; 
    struct Node *link;
};

struct Node *head = NULL; 

int length();

int main() {

    return 0;
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
    }while(temp != NULL);

    return count; 
}
