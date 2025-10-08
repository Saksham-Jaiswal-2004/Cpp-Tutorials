#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 1; j < n; j++) 
        {
            int idx = (i + j) % n;
            if (nums[idx] > nums[i]) 
            {
                ans[i] = nums[idx];
                break;
            }
        }
    }
    return ans;
}

int main() 
{
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> res = nextGreaterElements(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}
