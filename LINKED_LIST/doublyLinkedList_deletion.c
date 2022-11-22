#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * next;
    struct Node * prev;
};

void traversal(struct Node * head)
{
    struct Node * ptr = head;
    while(ptr != NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirst(struct Node * head)
{
    struct Node * p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}

struct Node * deleteAtIndex(struct Node * head,int index)
{
    struct Node * p = head;
    struct Node * q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    struct Node * r = q->next;
    p->next = r;
    r->prev = p;
    free(q);

    return head;
}

struct Node * deleteEnd(struct Node * head)
{
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct Node * deleteValue(struct Node * head,int value)
{
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value)
    {
        p->next = q->next;
        (q->next)->prev = p;
        free(q);
    }

    return head;
}

int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * forth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fivth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * seventh = (struct Node *)malloc(sizeof(struct Node));
    struct Node * eighth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = forth;
    third->prev = second;

    forth->data = 4;
    forth->next = fivth;
    forth->prev = third;

    fivth->data = 5;
    fivth->next = sixth;
    fivth->prev = forth;

    sixth->data = 6;
    sixth->next = seventh;
    sixth->prev = fivth;

    seventh->data = 7;
    seventh->next = eighth;
    seventh->prev = sixth;

    eighth->data = 8;
    eighth->next = NULL;
    eighth->prev = seventh;

    printf("\nBefore Deletion\n");
    traversal(head);

    printf("\nAfter Deletion\n");
    printf("\nDelete first element\n");
    head = deleteFirst(head);
    traversal(head);

    printf("\nDelete element at index 2\n");
    head = deleteAtIndex(head,2);
    traversal(head);
    
    printf("\nDelete end element\n");
    head = deleteEnd(head);
    traversal(head);

    printf("\nDelete element of value 5\n");
    head = deleteValue(head,5);
    traversal(head);

    return 0;
}