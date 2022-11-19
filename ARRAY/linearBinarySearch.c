#include <stdio.h>
int linearSearch(int arr[],int element,int size)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;  
}

int binarySearch(int arr[],int element,int size)
{
    int low = 0;
    int high = size-1;
    
    while(low<=high)
    {
        int mid = (high+low)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        else if(arr[mid] < element)
        {
            low = mid+1;
        }
        else if(arr[mid] > element)
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2,8,14,32,66,100,104,200,400};
    int size = sizeof(arr)/sizeof(int);
    int element = 200;
    int searchIndex = binarySearch(arr,element,size);
    printf("The element %d was found at the index %d\n",element,searchIndex);
    return 0;
}