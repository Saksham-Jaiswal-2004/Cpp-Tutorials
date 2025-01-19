#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    for(int i=1 ; i<n ; i++)
    {
        int temp = arr[i];
        int j=i-1;
        for(; j>=0 ; j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1]=temp;
    }
}

int main()
{
    vector<int> data = {24,97,2,6,88,13,77,98};
    int len = data.size();

    cout<<"Before Insertion Sort: "<<endl;
    for(int i: data)
    {
        cout<<i<<" ";
    }

    insertionSort(data, len);

    cout<<"\nAfter Insertion Sort: "<<endl;
    for(int i: data)
    {
        cout<<i<<" ";
    }
    return 0;
}