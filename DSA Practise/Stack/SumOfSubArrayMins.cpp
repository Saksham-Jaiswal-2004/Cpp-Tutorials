#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int sumSubarrayMins(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> s;

    // Previous Less Element (PLE)
    for (int i = 0; i < n; i++) 
    {
        while (!s.empty() && arr[s.top()] > arr[i])
            s.pop();
    
        left[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }

    while (!s.empty()) 
    s.pop();

    // Next Less Element (NLE)
    for (int i = n - 1; i >= 0; i--) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        right[i] = s.empty() ? n - i : s.top() - i;
        s.push(i);
    }

    long long sum = 0;
    int MOD = 1e9 + 7;

    for (int i = 0; i < n; i++) 
    {
        long long contrib = (long long)arr[i] * left[i] * right[i];
        sum = (sum + contrib) % MOD;
    }

    return (int)sum;
}

int main()
{
    vector<int> arr = {11,81,94,43,3};
    int res = sumSubarrayMins(arr);
    cout<<"Sum of Subarray Minimums: "<<res<<endl;

    return 0;
}