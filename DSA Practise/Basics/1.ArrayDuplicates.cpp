#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    if (nums.empty()) return 0;  // Edge case: empty array

    int j = 0;  // Slow pointer for unique elements
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[j]) {  // Found a new unique element
            j++;
            nums[j] = nums[i];  // Move unique element forward
        }
    }

    return j + 1;  // Number of unique elements
}

int main()
{
    vector<int> data = {-2,-1,0,0,1,1,1,2,2,3,3,4};
    // vector<int> data = {1,2,2};
    // vector<int> data = {1,1};
    // vector<int> data = {};

    int a = removeDuplicates(data);
    cout<<"Number of unique elements: "<<a<<endl;

    for(int i=0 ; i<a ; i++)
    {
        cout<<data[i]<<" ";
    }
    return 0;
}