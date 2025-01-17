#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> data = {12,76,43,57,98,21,12,56,5,2,78,53};
    int temp = data[0];
    int n = data.size();

    for(int i=0; i<n-1 ; i++)
    {
        int minIndex = i;
        for(int j=i+1 ; j<n ; j++)
        {
            if(data[minIndex]>data[j])
            {
                minIndex = j;
            }
        }
        swap(data[minIndex], data[i]);
    }

    cout<<"Sorted Array: ";
    for(int i: data)
    {
        cout<<i<<" ";
    }
    return 0;
}