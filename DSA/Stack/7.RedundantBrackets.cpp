#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> ele;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            ele.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                bool isRedundant = true;
                while (ele.top() != '(')
                {
                    char top = ele.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    ele.pop();
                }

                if(isRedundant)
                return true;

                ele.pop();
            }
        }
    }
}

int main()
{
    string s = "(a + (b*c))";
    
    if(findRedundantBrackets(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;

    return 0;
}