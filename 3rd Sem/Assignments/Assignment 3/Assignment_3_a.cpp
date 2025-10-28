#include<iostream>
#include<vector>

using namespace std;

vector<int> sumPair(vector<int>& data, int target)
{
    vector<int> ans;
    int left = 0;
    int right = data.size()-1;
    int sum;

    while(left<right)
    {
        sum = data[left] + data[right];
        if(sum == target)
        {
            ans.push_back(left+1);
            ans.push_back(right+1);
            return ans;
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}

int main()
{
    vector<int> data = {1,2,3,4,5,6,7,8,9,10};
    int T;

    cout<<"Enter Target Sum: ";
    cin>>T;

    vector<int> res = sumPair(data, T);

    if(res[0]!=-1 && res[1]!=-1)
    cout<<"Index of Pair: "<<res[0]<<", "<<res[1]<<endl;
    else
    cout<<"No such pair in the dataset whose sum is "<<T<<endl;

    return 0;
}