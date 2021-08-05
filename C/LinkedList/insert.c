#include <stdio.h>
#include <stdlib.h> //malloc

struct Node {
    int data;
    struct Node *next;
};

void traversal (struct Node * ptr){
    while (ptr!=NULL){
        printf("Element: %d\n ", ptr->data);
        ptr = ptr->next;
    }
    // if (ptr=NULL) {
    //     printf("null");
    // }

}

struct Node *atBegin (struct Node *head, int data){
    struct Node *new = (struct Node * )malloc(sizeof(struct Node));
    new->next = head;
    new->data = data;
    return new;

}
struct Node *inBetween(struct Node *head, int data, int index){
    struct Node *new = (struct Node * )malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i!=index-1){
        p = p->next;
        i+=1;
    }
    new->data = data;
    new->next = p->next;
    p->next = new;
    return new;
}    

struct Node *atEnd (struct Node *head, int data){
    struct Node *new = (struct Node * )malloc(sizeof(struct Node));
    struct Node *p = head;
    //int i = 0;

    while (p->next != NULL){
        p = p->next;
    }
    new->data = data;
    p->next = new;
    new->next = NULL;
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
    head = atBegin(head, 20);
    printf("after insertion\n");
    traversal(head);
    struct Node *temp = head; // to start traversal from begining
    head = inBetween(head,35,2);
    printf("Insertion at index 2 \n");
    traversal(temp);
    head = atEnd(head, 80);
    printf("after insertion at end\n");
    traversal(temp);    
    return 0;
}