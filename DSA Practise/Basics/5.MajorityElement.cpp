#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> count;
        int n = nums.size();
        for (int num : nums) 
        {
            count[num]++;
            if (count[num] > n / 2) 
            {
                return num;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> data1 = {2,2,1,1,1,2,2};
    vector<int> data2 = {3,2,3};
    vector<int> data = {6,5,5};

    Solution a;
    int ans = a.majorityElement(data);

    cout<<"Answer: "<<ans<<endl;
    return 0;
}