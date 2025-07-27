#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool knows(vector<vector<int>>& mat, int a, int b, int n)
{
    return mat[a][b] == 1;
}

int celebrity(vector<vector<int> >& mat) 
{
    stack<int> s;
    int n = mat.size();
    
    for(int i=0 ; i<n ; i++)
    {
        s.push(i);
    }

    while(s.size()>1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(mat, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    int candidate = s.top();
    bool rowCheck = false;
    int zeroCount = 0;

    for(int i=0 ; i<n ; i++)
    {
        if(mat[candidate][i] == 0)
        {
            zeroCount++;
        }
        if(i == candidate)
        {
            zeroCount++;
        }
    }

    if(zeroCount == n)
    rowCheck = true;

    bool colCheck = false;
    int oneCount = 0;

    for(int i=0 ; i<n ; i++)
    {
        if(mat[i][candidate] == 1)
        {
            oneCount++;
        }
        if(i == candidate)
        {
            oneCount--;
        }
    }

    if(oneCount == n-1)
    colCheck = true;

    if(rowCheck && colCheck)
    return candidate;
    else
    return -1;
}

int main()
{
    vector<vector<int>> data = {{1,1,0}, {0,1,0}, {0,1,1}};

    int ans = celebrity(data);
    
    if(ans!=-1)
    cout<<"Celebrity: "<<ans<<endl;
    else
    cout<<"No Celebrity in the given group!"<<endl;

    return 0;
}