#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> n1 = nums1;
    vector<int> n2 = nums2;
    vector<int> ans;
    int l1=0, l2=0;

    while(l1<n1.size())
    {
        while(n2[l2] != n1[l1])
        {
            l2++;
        }

        int pos = l2;

        while(l2<n2.size())
        {
            if(n2[l2] > n2[pos])
            {
                ans.push_back(n2[l2]);
                l1++;
                l2=0;
                break;
            }
            else if((n2[l2] < n2[pos] || n2[l2] == n2[pos]) && (l2==n2.size()-1))
            {
                ans.push_back(-1);
                l1++;
                l2=0;
                break;
            }
            else
            {
                l2++;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> num1 = {2,4};
    vector<int> num2 = {1,2,3,4};
    vector<int> res = nextGreaterElement(num1, num2);

    for(int i=0 ; i<num1.size() ; i++)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}