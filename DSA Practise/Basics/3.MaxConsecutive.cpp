#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, len = 0;

        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 1)
                len++;
            else
            {
                if(len>max)
                max = len;

                len = 0;
            }
        }
        if(len>max)
        max = len;

        return max;
    }
};

int main()
{
    vector<int> data = {1,1,0,1,1,1,1,0,0,1};

    Solution a;
    int ans = a.findMaxConsecutiveOnes(data);

    cout<<ans<<endl;

    return 0;
}