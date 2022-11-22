#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedList_traversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

// CASE 1:
struct Node * insertAtFirst(struct Node * head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// CASE 2:
struct Node * insertAtBetween(struct Node * head,int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head;
    int i = 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// CASE 3:
struct Node * insertAtEnd(struct Node * head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node * p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// CASE 4:
struct Node * insertAfterNode(struct Node * head,int data,struct Node * prevNode)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}



int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // Terminate the list at the third node
    third->data = 66;
    (*third).next = NULL;

    printf("\nLinked list before insertion\n");
    linkedList_traversal(head);

    printf("Linked list after insertion\n\n");

    printf("Linked list insertion at the beginning\n");
    head = insertAtFirst(head,1);
    linkedList_traversal(head);

    printf("Linked list insertion in between\n");
    head = insertAtBetween(head,56,2);
    linkedList_traversal(head);

    printf("Linked list insertion at the end\n");
    head = insertAtEnd(head,3);
    linkedList_traversal(head);

    printf("Linked list insertion after a node\n");
    head = insertAfterNode(head,4,second);
    linkedList_traversal(head);

    return 0;
}