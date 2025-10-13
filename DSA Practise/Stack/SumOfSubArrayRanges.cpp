#include<iostream>
#include<vector>
#include<stack>

using namespace std;

long long subArrayRanges(vector<int>& nums)
{}

int main()
{
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {1,3,3};
    vector<int> nums3 = {4,-2,-3,4,1};

    cout<<"Sum of Subarray Ranges: "<<subArrayRanges(nums1)<<endl;
    cout<<"Sum of Subarray Ranges: "<<subArrayRanges(nums2)<<endl;
    cout<<"Sum of Subarray Ranges: "<<subArrayRanges(nums3)<<endl;
    return 0;
}