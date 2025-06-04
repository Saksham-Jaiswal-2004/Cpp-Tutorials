#include<iostream>
#include<vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
    int len = nums.size();
    vector<int> res(len, 1);

    int left = 1;
    for(int i=0 ; i<len ; i++)
    {
        res[i] = left;
        left *= nums[i];
    }

    int right = 1;
    for(int i=len-1 ; i>=0 ; i--)
    {
        res[i] *= right;
        right *= nums[i];
    }

    return res;
}

int main()
{
    vector<int> data = {1,2,3,4};
    // vector<int> data = {-1,1,0,3,-3};
    data = productExceptSelf(data);

    for(int nums: data)
    {
        cout<<nums<<" ";
    }
    return 0;
}