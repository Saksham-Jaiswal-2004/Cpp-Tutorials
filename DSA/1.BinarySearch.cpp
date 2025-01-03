#include<iostream>

using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    // int mid = (start+end)/2;
    int mid = start + ((end-start)/2);


    while(start<=end) // Jbtk start index left me rhega and end index right me rhe ya phir same tbtk loop chalega
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

        // mid = (start+end)/2;
        mid = start + ((end-start)/2);
    }

    return -1;
}

int main()
{
    int even[6] = {5, 9, 13, 20, 26, 39};
    int odd[5] = {2, 12, 18, 25, 56};

    int evenIndex = binarySearch(even, 6, 9);
    int oddIndex = binarySearch(odd, 5, 25);

    cout<<"Index of 6 is: "<<evenIndex<<endl;
    cout<<"Index of 25 is: "<<oddIndex<<endl;
    
    return 0;
}