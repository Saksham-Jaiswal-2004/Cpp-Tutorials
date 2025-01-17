#include<iostream>
#include<vector>

using namespace std;

int single(vector<int> &arr)
{
    int ans=0;

    for(int i: arr)
    {
        ans = ans^i;
    }

    return ans;
}

int main()
{
    vector<int> data = {1, 2, 8, 6, 1, 6, 8};
    int ans = single(data);

    cout<<"Given Array:"<<endl;
    for(int i: data)
    {
        cout<<i<<" ";
    }

    cout<<"\n"<<endl;
    cout<<"Single Element in the given array is: "<<ans<<endl;

    return 0;
}