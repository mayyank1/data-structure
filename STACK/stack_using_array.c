#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr)
{
    if(ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack * ptr)
{
    if (ptr->top == (ptr->size)-1)
        return 1;
    else
        return 0;
    
}

void push(struct stack * ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack * ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("Pooped %d from the stack\n",val);
    }
    
}

int peek(struct stack * ptr,int i)
{
    int arrInd = ptr->top - i + 1;
    if(arrInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
        return ptr->arr[arrInd];
}

void display(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow");
    }
    else
    {
        for(int i = 1 ; i <= ptr->top + 1 ; i++)
        {
            printf("%d\n",peek(ptr,i));
        }
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

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
        push(s, val);
        break;

        case 2:
        pop(s);
        break;

        case 3:
        display(s);
        break;
        }
    } while(choice != 4);

    return 0;
}