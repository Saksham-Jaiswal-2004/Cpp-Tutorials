#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums)
{
    int counter = 0;
    while (counter < nums.size())
    {
        int max = 0;
        int maxIndex = 0;
        for (int j = 1; j <= nums[counter]; j++)
        {
            if(nums[counter+j]+counter >= nums.size()-1)
            {
                return true;
            }
            if(nums[counter]==0)
            break;
            if (nums[counter + j] >= max)
            {
                max = nums[counter + j];
                maxIndex = counter + j;
            }
        }
        counter = maxIndex;
    }
    return false;
}

int main()
{
    // vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    // cout << canJump(nums) << endl;
    cout << canJump(nums2) << endl;
    return 0;
}