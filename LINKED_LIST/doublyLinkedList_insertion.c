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

struct Node * insertFirst(struct Node * head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    head->prev = ptr;
    return ptr;
}

struct Node * insertBetween(struct Node * head,int data,int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    ptr->next = q;
    ptr->prev = p;
    p->next = ptr;
    q->prev = ptr;

    return head;
    
}

struct Node * insertEnd(struct Node * head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

    return head;
}

struct Node * insertAfterNode(struct Node * head,int data,struct Node * pre)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = pre->next;
    ptr->next = p;
    p->prev = ptr;
    ptr->prev = pre;
    pre->next = ptr;

    return head;
}

int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * forth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fivth = (struct Node *)malloc(sizeof(struct Node));

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
    fivth->next = NULL;
    fivth->prev = forth;

    printf("\nBefore insertion\n");
    traversal(head);

    printf("\nAfter insertion\n");
    printf("\nInsertion at first\n");
    head = insertFirst(head,22);
    traversal(head);

    printf("\nInsertion at index 2\n");
    head = insertBetween(head,44,2);
    traversal(head);

    printf("\nInsertion at end\n");
    head = insertEnd(head,66);
    traversal(head);

    printf("\nInsertion after a node\n");
    head = insertAfterNode(head,88,second);
    traversal(head);

    return 0;
}