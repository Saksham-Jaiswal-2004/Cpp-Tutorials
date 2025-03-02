#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total) {
        // Traverse from left to right
        for (int i = startingCol; i <= endingCol && count < total; i++) {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // Traverse from top to bottom
        for (int i = startingRow; i <= endingRow && count < total; i++) {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // Traverse from right to left
        for (int i = endingCol; i >= startingCol && count < total; i--) {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // Traverse from bottom to top
        for (int i = endingRow; i >= startingRow && count < total; i--) {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    
    return ans;
}

void display(vector<vector<int>>& arr)
{
    int row = arr.size();
    int column = arr[0].size();

    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<column ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void display2(vector<int>& arr)
{
    int len = arr.size();

    for(int i=0 ; i<len ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    srand(time(0));
    int n=3,m=3;

    // cout<<"Enter number of Rows and Colums: ";
    // cin>>n;
    // cin>>m;

    vector<vector<int>> arr(n, vector<int>(m));
    // vector<vector<int>> arr;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            arr[i][j] = rand()%100;
        }
    }

    cout<<"Initial Matrix:"<<endl;
    display(arr);

    vector<int> arr2 = spiralOrder(arr);
    cout<<"\nElements of Matrix in Spiral Order:"<<endl;
    display2(arr2);

    return 0;
}