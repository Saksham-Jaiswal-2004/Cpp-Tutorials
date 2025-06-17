#include<iostream>
#include<vector>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums)
{
    int positiveIndex = 0;
    int negativeIndex = 1;
    vector<int> res(nums.size(), 0);

    for(int i=0 ; i<nums.size() ; i++)
    {
        if(nums[i]<0)
        {
            res[negativeIndex] = nums[i];
            negativeIndex += 2;
        }
        else
        {
            res[positiveIndex] = nums[i];
            positiveIndex += 2;
        }
    }
    return res;
}

int main()
{
    vector<int> data = {3,1,-2,-5,2,-4};

    for(int i: data)
    cout<<i<<" ";
    cout<<endl;
    
    data = rearrangeArray(data);

    for(int i: data)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}