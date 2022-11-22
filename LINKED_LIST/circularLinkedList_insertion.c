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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertAtbetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = ptr;
    ptr->next = q;

    return head;
}

struct Node * insertAtEnd(struct Node * head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    struct Node *q = head->next;

    while(q != head)
    {
        p = p->next;
        q = q->next;
    }

    p->next = ptr;
    ptr->next = q;

    return head;
}

struct Node * insertAfterNode(struct Node * head,int data,struct Node * prevNode)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

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

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = fivth;

    fivth->data = 5;
    fivth->next = head;

    printf("\nBefore Insertion\n");
    traversal(head);

    printf("\nAfter Insertion\n");
    printf("\nInsert At First\n");
    head = insertAtFirst(head, 44);
    traversal(head);

    printf("\n");
    printf("\nInsert at index 2\n");
    head = insertAtbetween(head, 22,2);
    traversal(head);

    printf("\n");
    printf("\nInsert at end\n");
    head = insertAtEnd(head, 55);
    traversal(head);

    printf("\n");
    printf("\nInsert after forth node\n");
    head = insertAfterNode(head, 33, forth);
    traversal(head);
    return 0;
}