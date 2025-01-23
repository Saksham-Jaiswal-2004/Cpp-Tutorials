#include<iostream>
#include<vector>

using namespace std;

void reverse(vector<int> &nums)
{
    int s=0;
    int e=nums.size()-1;

    while(s<=e)
    {
        swap(nums[s++],nums[e--]);
    }
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n-1;
	int j = m-1;
	int carry=0;
	vector<int> ans;

	while(i>=0 && j>=0)
	{
		int sum = a[i] + b[j] + carry;
		carry = sum/10;
		sum %= 10;
		ans.push_back(sum);
		i--;
		j--;
	}

	while(i>=0)
	{
		int sum = a[i] + carry;
		carry = sum/10;
		sum %= 10;
		ans.push_back(sum);
		i--;
	}

	while(j>=0)
	{
		int sum = b[j] + carry;
		carry = sum/10;
		sum %= 10;
		ans.push_back(sum);
		j--;
	}

	while(carry!=0)
	{
		int sum = carry;
		carry = sum/10;
		sum %= 10;
		ans.push_back(sum);
	}

    reverse(ans);

	return ans;
}

int main()
{
    vector<int> data1 = {1,2,3,4};
    vector<int> data2 = {6};
    vector<int> data3 = {1,2,3};
    vector<int> data4 = {9,9};
    int n = data1.size();
    int m = data2.size();
    int o = data3.size();
    int p = data4.size();

    vector<int> answer = findArraySum(data1, n, data2, m);
    cout<<"Answer: "<<endl;
    for(int i: answer)
    {
        cout<<i<<" ";
    }

    answer = findArraySum(data3, o, data4, p);
    cout<<"\nAnswer: "<<endl;
    for(int i: answer)
    {
        cout<<i<<" ";
    }
    int a;
}