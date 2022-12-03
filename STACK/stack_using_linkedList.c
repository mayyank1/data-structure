#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * next;
};


int isEmpty(struct Node * top)
{
    if(top == NULL)
        return 1;
    return 0;
}

int isFull(struct Node * top)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
        return 1;
    return 0;
}

struct Node * push(struct Node * top,int data)
{
    if(isFull(top))
        printf("Stack Overflow\n");
    else
    {
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;

        ptr->next = top;
        return ptr;
    }
}

struct Node * pop(struct Node * top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node * ptr = top;
        top = top->next;

        free(ptr);
        return top;
    }
}

void display(struct Node * top)
{
    while (top != NULL) 
    {
        printf("Element : %d\n",top->data);
        top = top->next;
    }
    
}

int main()
{
    struct Node * top = NULL;
    int val,choice;
    do 
    {
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
        printf("\n Enter the number to be pushed on stack : ");
        scanf("%d",&val);
        top = push(top, val);
        break;

        case 2:
        top = pop(top);
        break;

        case 3:
        display(top);
        break;
        }
    } while(choice != 4);

    return 0;
}