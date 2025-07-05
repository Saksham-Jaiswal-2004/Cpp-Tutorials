#include<iostream>
#include<vector>
#include<map>

using namespace std;

int findLucky(vector<int>& arr) 
{
    map<int, int> res;
    int ans = -1;

    for(int i: arr)
    {
        res[i]++;
    }

    for(auto& i: res)
    {
        if(i.first == i.second)
        {
            if(i.first > ans)
            ans = i.first;
        }
    }
    cout<<endl;

    return ans;
}

void printList(vector<int> data)
{
    if(data.size() == 0)
    return;

    for(int i: data)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> data1 = {2,2,3,4};
    vector<int> data2 = {1,2,2,3,3,3};
    vector<int> data3 = {2,2,2,3,3};

    int ans1 = findLucky(data1);
    int ans2 = findLucky(data2);
    int ans3 = findLucky(data3);

    cout<<endl;

    printList(data1);
    printList(data2);
    printList(data3);

    cout<<endl;

    cout<<"Answer 1: "<<ans1<<endl;
    cout<<"Answer 2: "<<ans2<<endl;
    cout<<"Answer 3: "<<ans3<<endl;

    return 0;
}