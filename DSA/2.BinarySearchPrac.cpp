// Get and print the first and last occurence of a number in a sorted array
#include<iostream>

using namespace std;

int firstOccurence(int arr[], int n, int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(arr[mid] == n)
        {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return ans;
}

int lastOccurence(int arr[], int n, int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(arr[mid] == n)
        {
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return ans;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 2, 2, 2, 2};
    int n = 2;
    int size = sizeof(arr)/4;
    int first = firstOccurence(arr, n, size);
    int last = lastOccurence(arr, n, size);
    int freq = last - first + 1;
    cout<<"First Occurence of "<<n<<" is at index: "<<first<<endl;
    cout<<"Last Occurence of "<<n<<" is at index: "<<last<<endl;
    cout<<"Number of Occurences of "<<n<<" is: "<<freq<<endl;

    return 0;
}