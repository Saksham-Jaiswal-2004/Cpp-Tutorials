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

        if (arr[mid] >= arr[start])
        {
            start = mid + 1;
        } 
        else 
        {
            end = mid;
        }
        mid = start+(end-start)/2;
    }
    return mid+1;
}

int binarySearch(int arr[], int start, int end, int key)
{
    int mid = start + ((end-start)/2);


    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }

        if(arr[mid]>key)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
        mid = start + ((end-start)/2);
    }

    return -1;
}

int main()
{
    int data[] = {7, 8, 1, 3, 5};
    int size = sizeof(data)/sizeof(data[0]);
    int  pivotIndex = pivot(data, size);
    int index;

    int key=8;

    if(key>=data[pivotIndex] && key<=data[size-1])
    {
        index = binarySearch(data, pivotIndex, size-1, key);
    }
    else
    {
        index = binarySearch(data, 0, pivotIndex, key);
    }

    if(index==-1)
    {
        cout<<"Not found!"<<endl;
    }
    else
    {
        cout<<"Index of "<<key<<" is: "<<index<<endl;
    }

    return 0;
}