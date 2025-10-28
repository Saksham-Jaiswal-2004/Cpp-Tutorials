#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int boundedKnapsack(int W, vector<int>& wt, vector<int>& val, vector<int>& count, int n) 
{
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) 
    {
        int weight = wt[i], value = val[i], cnt = count[i];
        
        for (int k = 1; cnt > 0; k <<= 1) 
        {
            int use = min(k, cnt);
            int w = weight * use;
            int v = value * use;
            for (int j = W; j >= w; --j) 
            
            {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
            cnt -= use;
        }
    }
    return dp[W];
}

int main() 
{
    int n, W;
    
    cout<<"Enter number of items and weight: ";
    cin >> n >> W;

    vector<int> wt(n), val(n), count(n);
    for (int i = 0; i < n; ++i) 
    {
        cout<<"Enter weight, value, count of item "<<i+1<<": ";
        cin >> wt[i] >> val[i] >> count[i];
    }

    cout << "Maximum value: " << boundedKnapsack(W, wt, val, count, n) << endl;
    return 0;
}