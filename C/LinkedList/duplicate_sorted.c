#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n ", ptr->data);
        ptr = ptr->next;
    }
}

// struct Node *getValue(struct Node *head){
//     struct Node *current = head;

//     while (q->data != value && q->next != NULL){
//         p = p->next;
//         q = q->next;
//     }
//     if (q->data == value){
//         p->next = q->next;
//         free(q);
//     }
//     return head;
// }

struct Node *duplicate(struct Node *head)
{
    struct Node *current = head;

    while (current->next != NULL){
        if (current->data == current->next->data)
        {
            struct Node *temp;
            temp = current->next->next;
            free(current->next);
            current->next = temp;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    // allocate dynamic memory to the nodes (heap)
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    // add data to the nodes
    head->data = 9;
    second->data = 17;
    third->data = 17;
    forth->data = 32;

    // link the nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    traversal(head);

    printf("dupicates\n");
    head = duplicate(head);
    traversal(head);

    return 0;
}