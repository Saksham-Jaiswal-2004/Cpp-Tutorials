#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> arr;
    for (int num : nums) {
        arr.push_back(to_string(num));
    }

    sort(arr.begin(), arr.end(), [](string &a, string &b) {
        return a + b > b + a;
    });

    if (arr[0] == "0") return "0";

    string ans;
    for (string &s : arr) ans += s;

    return ans;
}

int main()
{
    vector<int> data = {9,30,5,34,3};

    cout<<"Data: ";
    for(int i: data)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    cout <<"Largest Number: "<<largestNumber(data)<< endl;
    return 0;
}