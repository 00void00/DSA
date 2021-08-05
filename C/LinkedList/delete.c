#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void traversal (struct Node * ptr){
    while (ptr!=NULL){
        printf("Element: %d\n ",ptr->data);
        ptr = ptr->next;
    }
    // if (ptr=NULL) {
    //     printf("null");
    // }
}
struct Node *atBegin(struct Node *head){
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}
struct Node *inBetween(struct Node *head, int index){
    struct Node *p = head;
    int i = 0;

    while (i != index-1){
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node *atEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL){
        p = p->next;
        q = q->next;
    }
    free(q);
    p->next = NULL;

    return head;
}

struct Node *getValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if (q->data == value){
        p->next = q->next;
        free(q);
    }
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
    forth->data = 32;

// link the nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
    
    traversal(head);

    // printf("deleting first node in LinkedList\n");
    // head = atBegin(head);
    // traversal(head);

    // printf("deleting any node in-between LinkedList\n");
    // head = inBetween(head, 2);
    // traversal(head);

    printf("deleting last node in LinkedList\n");
    head = atEnd(head);
    traversal(head);

    printf("deleting last node in LinkedList\n");
    head = getValue(head, 17);
    traversal(head);    

    return 0;
}