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
void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    for(int i=m ; i<m+n ; i++)
    {
        nums1[i] = nums2[i-m];
    }

    for(int i=0 ; i<m+n ; i++)
    {
        for(int j=0 ; j<m+n-i-1 ; j++)
        {
            if(nums1[j] > nums1[j+1])
            {
                swap(nums1[j], nums1[j+1]);
            }
        }
    }
    printArray(nums1);
}

// Approach 2
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i=0, j=0, k=0;

    vector<int> arr(m+m);

    while(i<n && j<m)
    {
        if(nums1[i]<nums2[j])
        {
            arr[k++] = nums1[i++];
        }
        else
        {
            arr[k++] = nums2[j++];
        }
    }

    while(i<n)
    {
        arr[k++] = nums1[i++];
    }

    while(j<m)
    {
        arr[k++] = nums2[j++];
    }

    printArray(arr);
}

int main()
{
    vector<int> n1 = {1,2,3,0,0,0}; 
    vector<int> n2 = {2,5,6};

    int l1 = n1.size() - n2.size();
    int l2 = n2.size();

    mergeArrays(n1, l1, n2, l2);
    merge(n1, l1, n2, l2);
    return 0;
}