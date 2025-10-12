#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    heights.push_back(0);
    stack<int> index;
    int maxArea = 0;
    int i=0;

    while(i<heights.size())
    {
        int area, width;

        if(index.empty())
        {
            index.push(i);
            i++;
            continue;
        }

        if(heights[i] < heights[index.top()])
        {
            int poppedHeight = heights[index.top()];
            index.pop();
            if(index.empty())
            {
                width = i;
            }
            else
            {
                width = i - index.top() - 1;
            }

            area = width*poppedHeight;
            maxArea = max(area, maxArea);
        }
        else
        {
            index.push(i);
            i++;
        }
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {1,1};
    int res = largestRectangleArea(heights);
    cout<<"Largest Rectangle Area for the given Histogram: "<<res<<endl;

    return 0;
}