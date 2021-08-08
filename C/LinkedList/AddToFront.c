#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void traversal (struct Node * ptr){
    while (ptr!=NULL){
        printf(" -> %d ", ptr->data);
        ptr = ptr->next;
    }
}
// struct Node * head;
struct Node *toFront(struct Node *head){
    struct Node *ptr = head;

    while (ptr->next->next != NULL){
        ptr = ptr->next;
    }
    struct Node *q = ptr;
    struct Node *last = ptr->next;
    last->next = head;
    q->next = NULL;
    head = last;
    
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * forth;
// allocate dynamic memory to the nodes (heap)
    head = (struct Node * )malloc(sizeof(struct Node));
    second = (struct Node * )malloc(sizeof(struct Node));
    third = (struct Node * )malloc(sizeof(struct Node));
    forth = (struct Node * )malloc(sizeof(struct Node));

// add data to the nodes
    head->data = 9;
    second->data = 17;
    third->data = 21;
    forth->data = 27;

// link the nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
    
    printf("LinkedList before removing\n");
    traversal(head);

    printf("\nLinkedList after removing last node\n");
    head = toFront(head);    
    traversal(head);
    return 0;
}