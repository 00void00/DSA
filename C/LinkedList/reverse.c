#include <stdio.h>
#include <stdlib.h> //malloc

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

struct Node *reverse(struct Node *head){
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
    
    printf("LinkedList before reversing\n");
    traversal(head);

    printf("\nLinkedList after reversing\n");
    head = reverse(head);    
    traversal(head);
    return 0;
}