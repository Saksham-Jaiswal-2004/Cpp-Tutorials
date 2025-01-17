#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v1(4,2);
    vector<char> v2 = {'a', 'b', 'c', 'd', 'e'};
    v2.push_back('f');
    // cout<<v[0]<<endl;
    // cout<<v[1]<<endl;
    // cout<<v[2]<<endl;
    // cout<<v[3]<<endl;

    v1.push_back(3);

    cout<<"Size of Vector: "<<v1.size()<<endl;
    cout<<"Capacity of Vector: "<<v1.capacity()<<endl;

    cout<<"Size of Vector: "<<v2.size()<<endl;
    cout<<"Capacity of Vector: "<<v2.capacity()<<endl;

    for(char i: v2)
    {
        cout<<i<<endl;
    }
    return 0;
}