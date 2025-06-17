#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) 
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<bool> row(rows, false);
    vector<bool> col(cols, false);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (matrix[i][j] == 0)
                row[i] = col[j] = true;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (row[i] || col[j])
                matrix[i][j] = 0;
}

void printMatrix(vector<vector<int>> mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> data1 = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> data2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    cout<<"Original Matrix:"<<endl;
    printMatrix(data1);
    setZeroes(data1);
    cout<<"Modified Matrix:"<<endl;
    printMatrix(data1);

    return 0;
}