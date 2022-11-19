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

int indDeletion(int arr[] ,int size  ,int capacity ,int index)
{
    if(size>=capacity)
    {
        return -1;
    }
    else
    {
        for (int i = index; i < size-1 ; i++)
        {
            arr[i] = arr[i+1];
        }
        return 1;
        
    }
}

int main()
{
    int arr[100] = {1,2,6,78};
    int size = 4;
    int element = 45;
    int index = 2;
    int capacity = sizeof(arr);
    display(arr,size);
    int result = indDeletion(arr ,size ,capacity ,index);
    size--;
    display(arr,size);
}