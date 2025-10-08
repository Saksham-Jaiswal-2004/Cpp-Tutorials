#include<iostream>
#include<vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> ans;

    for(int i=0 ; i<nums1.size() ; i++)
    {
        int flag = 0;
        int flag2 = 0;
        int var;

        for(int j=0 ; j<nums2.size() ; j++)
        {
            if(flag==1 && var<nums2[j])
            {
                ans.push_back(nums2[j]);
                flag2 = 1;
                break;
            }

            if(nums1[i]==nums2[j])
            {
                flag = 1;
                var = nums2[j];
            }

            if(j==nums2.size()-1 && flag2==0)
            {
                ans.push_back(-1);
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4,1,2,0}, nums2 = {3,4,2,0,1};
    vector<int> res = nextGreaterElement(nums1, nums2);
    for(int i: res)
    cout<<i<<" ";
    cout<<endl;

    return 0;
}