#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node * deleteFirst(struct Node *head)
{
    struct Node * ptr = head;
    struct Node * q = head->next;
    while(q->next != head)
    {
        q = q->next;
    }

    head = head->next;
    q->next = head;

    free(ptr);
    return head;
}

struct Node * deleteBetween(struct Node *head,int index)
{
    struct Node * p = head;
    struct Node * q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}   

struct Node * deleteEnd(struct Node * head)
{
    struct Node * p = head->next;
    struct Node * q = head;
    while(p->next != head)
    {
        p = p->next;
        q = q->next;
    }
    q->next = head;
    free(p);
    return head;
}

struct Node * deleteAtGivenValue(struct Node * head,int value)
{
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data != value && q->next != head)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fivth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seventh = (struct Node *)malloc(sizeof(struct Node));
    struct Node *eighth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = fivth;

    fivth->data = 5;
    fivth->next = sixth;

    sixth->data = 6;
    sixth->next = seventh;

    seventh->data = 7;
    seventh->next = eighth;

    eighth->data = 8;
    eighth->next = head;

    printf("\nBefore Deletion\n");
    traversal(head);

    printf("\nAfter Deletion\n");
    printf("\nDelete the first element\n");
    head = deleteFirst(head);
    traversal(head);

    printf("\nDelete the element at index 2\n");
    head = deleteBetween(head,2);
    traversal(head);

    printf("\nDelete the element at end\n");
    head = deleteEnd(head);
    traversal(head);

    printf("\nDelete the element of data 5\n");
    head = deleteAtGivenValue(head,5);
    traversal(head);
    return 0;
}