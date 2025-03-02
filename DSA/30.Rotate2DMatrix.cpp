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

void rotate(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> rot(3);

    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            cout<<matrix[i][j]<<endl;
            rot[j][col-1-i] = matrix[i][j];
        }
    }

    display(rot);
}

int main()
{
    int num=1, n=3, m=3;
    vector<vector<int>> data(n, vector<int> (m));
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            data[i][j] = num++;
        }
    }

    display(data);
    rotate(data);
}