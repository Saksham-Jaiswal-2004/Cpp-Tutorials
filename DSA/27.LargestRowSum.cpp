#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void display(int arr[3][3], int row, int col)
{
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int arrSum(int arr[3][3], int row, int col)
{
    int max=0, pos;
    int maximum[row];
    for(int i=0 ; i<row ; i++)
    {
        int sum = 0;
        for(int j=0 ; j<col ; j++)
        {
            sum += arr[i][j];
        }
        maximum[i] = sum;
        if(sum>max)
        {
            max = sum;
            pos = i;
        }
        cout<<endl;
    }

    for(int i=0 ; i<row ; i++)
    {
        cout<<"Sum of Row Index "<<i<<" = "<<maximum[i]<<endl;
    }

    return pos;
}

int main()
{
    srand(time(0));
    int n=3,m=3;
    int arr[n][3];

    // cout<<"Enter Number of Rows and Columns:"<<endl;
    // cin>>n;
    // cin>>m;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            arr[i][j] = rand()%100;
        }
    }

    display(arr, n, m);
    int sum = arrSum(arr, n, m);

    cout<<sum<<" index row has the maximum sum."<<endl;
    return 0;
}