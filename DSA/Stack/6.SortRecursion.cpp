#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void sortInsert(stack<int> &stack, int data)
{
    if(stack.empty())
    {
        stack.push(data);
    }
    else
    {
        if(stack.top() < data)
        {
            stack.push(data);
        }
        else
        {
            int num = stack.top();
            stack.pop();
            sortInsert(stack, data);
            stack.push(num);
        }
    }
}

void sortStack(stack<int> &stack)
{
    if(stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortInsert(stack, num);
}

int main()
{
    stack<int> s,q;
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-2);
    s.push(5);

    q = s;
    int len = s.size();

    for(int i=0 ; i<len ; i++)
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;

    sortStack(s);

    for(int i=0 ; i<len ; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}