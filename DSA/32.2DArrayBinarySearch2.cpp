#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
    int row = matrix.size();
    int col = matrix[0].size();
    
    int rowIndex = 0;
    int colIndex = col-1;
    
    while(rowIndex < row && colIndex>=0 ) {
        int element = matrix[rowIndex][colIndex];
        
        if(element == target) {
            return 1;
        }
        
        if(element < target){
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return 0;
}


int main()
{
    int num;
    vector<vector<int>> data = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    for(int i=0 ; i<data.size() ; i++)
    {
        for(int j=0 ; j<data[0].size() ; j++)
        {
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nEnter element to be searched: ";
    cin>>num;

    if(searchMatrix(data, num))
    cout<<"Element Present!"<<endl;
    else
    cout<<"Element Not Present!"<<endl;
    return 0;
}