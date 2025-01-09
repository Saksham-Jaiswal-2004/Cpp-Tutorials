// Searching the pivot element in a sorted rotated array
#include<iostream>

using namespace std;

int pivot(int arr[], int size)
{
    int start=0;
    int end=size-1;
    int mid = start+(end-start)/2;

    while(start<=end)
    {
        if(arr[mid]>arr[mid+1])
        {
            return mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return mid+1;
}

int main()
{
    int arr1[] = {7, 9, 10, 5, 6,};
    int pivotIndex = pivot(arr1, 5);
    cout<<"Pivot of given array is at index: "<<pivotIndex<<endl;

    return 0;
}