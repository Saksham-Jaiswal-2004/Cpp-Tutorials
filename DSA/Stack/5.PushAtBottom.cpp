#include<iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> insertAtBottom(stack<int>& stack, int data)
{
    if(stack.empty())
    {
        stack.push(data);
        return stack;
    }

    int num = stack.top();
    stack.pop();
    stack = insertAtBottom(stack, data);
    stack.push(num);
    return stack;
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    myStack = insertAtBottom(myStack, x);
    return myStack;
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);
    s = pushAtBottom(s, 9);

    int len = s.size();

    for(int i=0 ; i<len ; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}