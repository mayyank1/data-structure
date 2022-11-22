#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedList_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
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

struct Node * deleteAtEnd(struct Node *head)
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

struct Node * deleteGivenValue(struct Node *head,int value)
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
        free(q);
    }

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    struct Node *fivth;
    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    fivth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 2;
    head->next = second;

    // link second and third nodes
    second->data = 4;
    second->next = third;

    // link third and forth nodes
    third->data = 8;
    (*third).next = forth;

    // link forth and fivth nodes
    forth->data = 12;
    (*forth).next = fivth;

    // Terminate the list at the fivth node
    fivth->data = 36;
    (*fivth).next = NULL;

    printf("\nLinked list before deletion\n");
    linkedList_traversal(head);

    printf("\nLinked list after deletion\n");

    printf("\nDeleting the first Node of Linked list\n");
    head = deleteFirst(head);
    linkedList_traversal(head);

    printf("\nDeleting a node in between Linked list\n");
    head = deleteBetween(head,2);
    linkedList_traversal(head);

    printf("\nDeleting the last Node of Linked list\n");
    head = deleteAtEnd(head);
    linkedList_traversal(head);

    printf("\nDeleting a Node with the given value from the Linked list\n");
    head = deleteGivenValue(head,4);
    linkedList_traversal(head);

    return 0;
}