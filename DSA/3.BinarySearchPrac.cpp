// Peak Index in Mountain Array
#include<iostream>

using namespace std;

int peakIndex(int arr[], int size)
{
    int start=0;
    int end=size-1;
    int mid = start + (end-start)/2;

    while(start<=end)
    {
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            return mid;
        }
        else if(arr[mid]<arr[mid-1])
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
}

int main()
{
    int arr1[] = {0, 1, 2, 1, 0};
    int arr2[] = {0, 10, 5, 2};

    int size = sizeof(arr1)/4;
    int index = peakIndex(arr1, size);
    cout<<"Index of peak element in array is: "<<index<<endl;

    size = sizeof(arr2)/4;
    index = peakIndex(arr2, size);
    cout<<"Index of peak element in array is: "<<index<<endl;

    return 0;
}