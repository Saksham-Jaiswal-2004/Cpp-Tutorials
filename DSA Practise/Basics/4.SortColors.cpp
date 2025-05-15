#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for(int i=0 ; i<n-1 ; i++)
        {
            for(int j=0 ; j<n-i-1 ; j++)
            {
                if(nums[j]>nums[j+1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }
};

int main()
{
    vector<int> data = {2,0,2,1,1,0};

    Solution sort;
    sort.sortColors(data);

    for(int i=0 ; i<data.size() ; i++)
    cout<<data[i]<<" ";
    
    return 0;
}