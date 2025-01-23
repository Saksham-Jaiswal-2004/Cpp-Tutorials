#include<iostream>
#include<vector>

using namespace std;

int pivot(vector<int> &nums)
{
    int start = 0;
    int end = nums.size()-1;
    int mid = start + (end-start)/2;

    while(start<=end)
    {
        if(nums[mid]>nums[mid+1])
        {
            return mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return mid+1;
}

// Approach 1
bool check1(vector<int> &nums)
{
    int len = nums.size();
    int index = pivot(nums);
    for(int i=0 ; i<len ; i++)
    {
        if(i==index-1)
        {
            continue;
        }
        else
        {
            if(nums[i]>nums[i+1])
            {
                return false;
            }
        }
    }
    return true;
}

// Approach 2
bool check2(vector<int> &nums)
{
    int len = nums.size();
    int pair=0;
    for(int i=1 ; i<len ; i++)
    {
        if(nums[i-1]>nums[i])
        {
            pair++;
        }
    }
    if(nums[len-1]>nums[0])
    {
        pair++;
    }
    
    if(pair>1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    vector<int> data = {3,4,5,1,2};
    cout<<"Answer: "<<check1(data)<<endl;
    cout<<"Answer: "<<check2(data)<<endl;
    return 0;
}