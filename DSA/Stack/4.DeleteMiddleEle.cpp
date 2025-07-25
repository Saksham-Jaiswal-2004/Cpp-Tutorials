#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

void solve(stack<int>&inputStack, int count, int size)
{
   if(count == size/2) 
   {
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();

   solve(inputStack, count+1, size);
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N)
{
   int count = 0;
   solve(inputStack, count, N);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    deleteMiddle(s, s.size());

    int len = s.size();
    for(int i=0 ; i<len ; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}