#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len+1, 0);

        for(int i: nums)
        {
            result[i]++;
        }

        for(int i=0 ; i<len+1 ; i++)
        {
            if(result[i] == 0)
                return i;
        }

        return -1;
    }
};

int main()
{
    vector<int> data = {0,1,2,4};

    Solution sol;
    int ans = sol.missingNumber(data);

    cout<<ans<<endl;
    return 0;
}