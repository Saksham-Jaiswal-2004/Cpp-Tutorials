#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void display(vector<int> arr)
{
    int len = arr.size();
    for(int i=0 ; i<len ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void display2(vector<vector<int>> arr, int nRows, int mCols)
{
    for(int i=0 ; i<nRows ; i++)
    {
        for(int j=0 ; j<mCols ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    
    for(int col=0 ; col < mCols ; col++)
    {
        if(col&1)
        {
            for(int row = nRows-1 ; row>=0 ; row--)
            ans.push_back(arr[row][col]);
        }
        else
        {
            for(int row=0 ; row<nRows ; row++)
            ans.push_back(arr[row][col]);
        }
    }

    return ans;
}

int main()
{
    srand(time(0));
    int n=3,m=3;
    vector<vector<int>> arr(n, vector<int>(m));

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            arr[i][j] = rand()%100;
        }
    }

    display2(arr, n, m);

    display(wavePrint(arr, n, m));
    return 0;
}