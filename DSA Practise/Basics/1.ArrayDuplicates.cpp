#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    int len = nums.size();
    int count = 0;

    for(int i=0 ; i<len-1 ; i++)
    {
        if(nums[i] != nums[i+1])
        {
            count++;
            cout<<nums[i]<<" : "<<nums[i+1]<<endl;
        }
        else
        {
            for(int j=i ; j<len ; j++)
            {
                nums[j] = nums[j+1];
            }
            i--;
        }
    }

    for(int i: nums)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return count+1;
}

int main()
{
    vector<int> data = {0,0,0,1,1,2,3,4,5,5};

    cout<<"Number of unique elements: "<<removeDuplicates(data)<<endl;
    return 0;
}