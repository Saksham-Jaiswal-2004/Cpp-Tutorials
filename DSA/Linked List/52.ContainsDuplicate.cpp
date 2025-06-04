#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
    unordered_set<int> seen;
    for (int num : nums) 
    {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}

int main()
{
    vector<int> data = {};

    if(containsDuplicate(data))
    cout<<"Contains Duplicate"<<endl;
    else
    cout<<"Does not contains Duplicate"<<endl;

    return 0;
}