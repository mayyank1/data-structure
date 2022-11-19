#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int totalSize;
    int usedSize;
    int *index;
};

void createArray(struct myArray* a,int tSize,int uSize)
{
    (*a).totalSize = tSize;
    (*a).usedSize = uSize;
    (*a).index = (int *) malloc(tSize*sizeof(int));
}

void show(struct myArray *a)
{
    for(int i = 0;i < (*a).usedSize; i++)
    {
        printf("%d\n",((*a).index)[i]);
    }
}

void setValue(struct myArray *a)
{
    int n;
    for(int i = 0;i < (*a).usedSize; i++)
    {
        printf("Enter element %d\n",i+1);
        scanf("%d",&n);
        ((*a).index)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks,100,20);
    printf("We are running setValue now\n");
    setValue(&marks);
    printf("We are running show now\n");
    show(&marks);
    return 0;
}