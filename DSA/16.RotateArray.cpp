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

// Approach 1 - But time limit is getting exceeded with this approach
void rotateArray1(vector<int> &nums, int k)
{
    int len = nums.size();

    while(k>0)
    {
        int buffer = nums[len-1];
        for(int i=len-1 ; i>0 ; i--)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = buffer;
        k--;
    }

    printArray(nums);
}

// Approach 2 - Runtime Error - Vector overflow
void rotateArray2(vector<int> &nums, int k)
{
    int len = nums.size();
    int l=k;
    vector<int> copy(len);
    
    for(int i=0 ; i<len ; i++)
    {
        if(k>0)
        {
            copy[i] = nums[len-k];
            k--;
        }
        else
        {
            copy[i] = nums[i-l];
        }
    }

    nums = copy;

    printArray(nums);
}

// Approach 3
void rotateArray3(vector<int> &nums, int k)
{
    int len = nums.size();
    vector<int> copy(len);
    
    for(int i=0 ; i<len ; i++)
    {
        copy[(i+k)%len] = nums[i];
    }

    nums = copy;

    printArray(nums);
}

int main()
{
    vector<int> data = {1,2,3,4,5,6,7};
    // vector<int> data = {-1,-100,3,99};
    int k=3;

    printArray(data);

    rotateArray3(data, k);

    return 0;
}