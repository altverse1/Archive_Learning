//Binary Search
#include <stdio.h>
#include <stdlib.h>

int binarysearch(int arr[],int start, int end, int find)
{
    if(end>=start)
    {
        int mid = start+(end-start)/2;
        if(arr[mid] == find)
            return mid;
        if(arr[mid]<find)
            return binarysearch(arr,mid+1, end, find);
        else 
            return binarysearch(arr, start, mid-1, find );
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,2,4,5,6,7,8,11};
    int find = 7;
    int total = 7;
    int found = binarysearch(arr, 0, total-1, find);
    if(found == -1)
        printf("Not Found");
    else
        printf("Found at %d\n",found);

    return 0;
}