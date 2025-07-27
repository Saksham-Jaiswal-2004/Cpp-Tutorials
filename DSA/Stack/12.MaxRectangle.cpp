#include <iostream>
#include <vector>
#include <stack>
#include<climits>

using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    vector<int> prev(n);

    next = nextSmallerElement(heights, n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1)
            next[i] = n;

        int l = heights[i];
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}

int maxArea(vector<vector<int>> &mat)
{
    int area = largestRectangleArea(mat[0]);

    for(int i=1 ; i<mat.size() ; i++)
    {
        for(int j=0 ; j<mat[0].size() ; j++)
        {
            if(mat[i][j] != 0)
            mat[i][j] += mat[i-1][j];
            else
            mat[i][j] = 0;
        }

        area = max(area, largestRectangleArea(mat[i]));
    }

    return area;
}

void printMatrix(vector<vector<int>> mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> data = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    cout << "Given Matrix: " << endl;
    printMatrix(data);
    cout << endl;

    int ans = maxArea(data);
    cout << "Max Area of 1's Rectangle: " << ans << endl;

    return 0;
}