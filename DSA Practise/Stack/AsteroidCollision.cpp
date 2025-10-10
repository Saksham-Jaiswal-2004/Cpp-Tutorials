#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> ans;
    stack<int> row;
    int index = 0;
    row.push(asteroids[index]);
    index++;

    while (index < asteroids.size())
    {
        if (row.empty())
        {
            row.push(asteroids[index]);
            index++;
            continue;
        }
        if (row.top() > 0 && asteroids[index] < 0 && abs(row.top()) == abs(asteroids[index]))
        {
            row.pop();
            index++;
            continue;
        }

        if (row.top() > 0 && asteroids[index] < 0 && abs(row.top()) > abs(asteroids[index]))
        {
            index++;
        }
        else if (row.top() > 0 && asteroids[index] < 0 && abs(row.top()) < abs(asteroids[index]))
        {
            row.pop();
        }
        else
        {
            row.push(asteroids[index]);
            index++;
        }
    }

    while(!row.empty())
    {
        ans.push_back(row.top());
        row.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> asteroids = {5, -5};
    vector<int> res = asteroidCollision(asteroids);
    cout << "Result: " << endl;
    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}