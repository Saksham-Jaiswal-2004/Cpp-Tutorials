#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(3);
    s.push(5);

    cout<<"Top: "<<s.top()<<endl;
    cout<<"Empty: "<<s.empty()<<endl;

    return 0;
}