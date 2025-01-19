#include<iostream>
#include<vector>

using namespace std;

int main()
{
    // vector<int> data = {10, 1, 7, 6, 14, 9};
    vector<int> data = {8, 22, 7, 9, 31, 5, 13};
    int n = data.size(), counter=0;
    bool swapped=true;

    cout<<"Original Array:"<<endl;
    for(int i: data)
    {
        cout<<i<<" ";
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(data[j] > data[j+1])
            {
                // int temp = data[j];
                // data[j] = data[j+1];
                // data[j+1] = temp;
                swap(data[j], data[j+1]);
                counter++;
                swapped=false;
            }
        }

        if(swapped) //If swapped remains true that means array is already sorted, and by this we can make best case time complexity = O(n).
        {
            break;
        }
    }

    cout<<"\n\nSorted Array:"<<endl;
    for(int i: data)
    {
        cout<<i<<" ";
    }

    cout<<"\n\nNumber of swaps: "<<counter<<endl;
    return 0;
}