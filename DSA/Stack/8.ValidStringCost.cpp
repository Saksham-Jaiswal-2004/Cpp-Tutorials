#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findMinimumCost(string str)
{
    stack<char> ele;

    if (str.length() % 2 != 0)
        return -1;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
            ele.push(ch);
        else
        {
            if (!ele.empty() && ele.top() == '{')
                ele.pop();
            else
                ele.push(ch);
        }
    }

    int a = 0, b = 0;
    while (!ele.empty())
    {
        if (ele.top() == '{')
            b++;
        else
            a++;

        ele.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string data1 = "{{{}";
    string data2 = "{{{{";
    string data3 = "{{{}}";

    cout << findMinimumCost(data1) << endl;
    cout << findMinimumCost(data2) << endl;
    cout << findMinimumCost(data3) << endl;

    return 0;
}