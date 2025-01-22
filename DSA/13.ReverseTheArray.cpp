#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int> &arr)
{
    cout<<"\n\nNew Array:"<<endl;
    for(int i: arr)
    {
        cout<<i<<" ";
    }
}


// Approach 1
void reverseArray(vector<int> &arr, int m)
{
    int len = arr.size();
    vector<int> newArr = arr;
    for(int i=0 ; i<len ; i++)
    {
        if(i<=m)
        {
            arr[i] = newArr[i];
        }
        else
        {
            arr[i] = newArr[len-i+m];
        }
    }

    printArray(arr);
}

// Approach 2
void reverse(vector<int> &arr, int m)
{
    int start=m+1, end=arr.size()-1;

    while(start<=end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> data1 = {1, 2, 3, 4, 5, 6};
    vector<int> data2 = {10, 9, 8, 7, 6};
    int position1 = 3;
    int position2 = 2;

    cout<<"Initial Array-1:"<<endl;
    for(int i: data1)
    {
        cout<<i<<" ";
    }

    cout<<"\nInitial Array-2:"<<endl;
    for(int i: data2)
    {
        cout<<i<<" ";
    }

    reverseArray(data1, position1);
    reverse(data2, position2);

    return 0;
}