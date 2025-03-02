#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void display(vector<vector<int>>& arr)
{
    int row = arr.size();
    int col = arr[0].size();

    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row*col - 1;
    int mid = start + (end-start)/2;

    while(start<=end)
    {
        int element = matrix[mid/col][mid%col];

        if(element==target)
        {
            return 1;
        }

        if(element<target)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }

        mid = start + (end-start)/2;
    }

    return 0;
}

int main()
{
    int m=3,n=3,num;
    vector<vector<int>> arr(m, vector<int>(n));
    srand(time(0));
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            arr[i][j] = rand()%100;
        }
    }

    display(arr);

    cout<<"Enter element to search: ";
    cin>>num;
    if(searchMatrix(arr, num))
    cout<<"Element is present!"<<endl;
    else
    cout<<"Element is not present!"<<endl;
    
    return 0;
}