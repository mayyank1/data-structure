#include <stdio.h>

// Traversal
void display(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[] ,int size ,int element ,int capacity ,int index)
{
    if(size>=capacity)
    {
        return -1;
    }
    else
    {
        for (int i = size-1; i >= index ; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        return 1;
        
    }
}

int main()
{
    int arr[100] = {1,2,6,78};
    int size = 4;
    int element = 45;
    int index = 3;
    int capacity = sizeof(arr);
    display(arr,size);
    int result = indInsertion(arr ,size ,element ,capacity ,index);
    size++;
    if(result == 1)
    {
        display(arr,size);
    }
    else
    {
        printf("Insertion Failed"); 
    }
    return 0;
}