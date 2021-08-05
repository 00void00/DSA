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
    // if (ptr=NULL) {
    //     printf("null");
    // }

}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
// allocate dynamic memory to the nodes (heap)
    head = (struct Node * )malloc(sizeof(struct Node));
    second = (struct Node * )malloc(sizeof(struct Node));
    third = (struct Node * )malloc(sizeof(struct Node));

// add data to the nodes
    head->data = 9;
    second->data = 17;
    third->data = 21;

// link the nodes
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    traversal(head);
    return 0;
}