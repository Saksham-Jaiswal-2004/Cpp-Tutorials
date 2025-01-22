#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<int> &arr)
{
    cout<<"\nArray:"<<endl;
    for(int i: arr)
    {
        cout<<i<<" ";
    }
}

// Approach 1
void moveZeroes(vector<int> &nums)
{
    int len = nums.size(), j=0;
    vector<int> store(len,0);

    for(int i=0 ; i<len ; i++)
    {
        if(nums[i]!=0)
        {
            store[j++] = nums[i];
        }
    }
    nums = store;

    printArray(nums);
}

// Approach 2
void move(vector<int> &nums)
{
    int len = nums.size(), j=0;

    for(int i=0 ; i<len ; i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[i], nums[j++]);
        }
    }

    printArray(nums);
}

int main()
{
    vector<int> data1 = {0,1,0,3,12};
    vector<int> data2 = {0,1,0,0,6,9,0,23};
    printArray(data1);
    printArray(data2);

    moveZeroes(data1);
    move(data2);
    return 0;
}