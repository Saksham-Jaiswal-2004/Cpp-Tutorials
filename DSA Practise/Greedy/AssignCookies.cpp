#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int children_count = 0;
    int cookie_count = 0;
    int content_children = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (children_count < g.size() && cookie_count < s.size())
    {
        if(g[children_count]<=s[cookie_count])
        {
            content_children++;
            children_count++;
        }

        cookie_count++;
    }

    return content_children;
}

int main()
{
    vector<int> g = {1,2,3}, s = {1,1,};
    cout<<findContentChildren(g, s)<<endl;;
    return 0;
}