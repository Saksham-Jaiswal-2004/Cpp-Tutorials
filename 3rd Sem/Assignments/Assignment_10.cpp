#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job 
{
    int start, finish, profit, power;
};

int latestNonConflict(const vector<Job>& jobs, int i) 
{
    for (int j = i - 1; j >= 0; j--) 
    {
        if (jobs[j].finish <= jobs[i].start)
            return j;
    }
    return -1;
}

int getMaxProfit(vector<Job>& jobs, int i, int E, vector<vector<int>>& dp, vector<int>& p) 
{
    if (i < 0 || E <= 0)
        return 0;

    if (dp[i][E] != -1)
        return dp[i][E];

    int exclude = getMaxProfit(jobs, i - 1, E, dp, p);

    int include = 0;
    if (jobs[i].power <= E)
        include = jobs[i].profit + getMaxProfit(jobs, p[i], E - jobs[i].power, dp, p);

    dp[i][E] = max(include, exclude);
    return dp[i][E];
}

int main() 
{
    vector<Job> jobs = {{1, 3, 20, 4}, {3, 5, 10, 2}, {6, 9, 100, 10}, {7, 8, 70, 5}};

    int E = 12;

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) 
    {
        return a.finish < b.finish;
    });

    int n = jobs.size();

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = latestNonConflict(jobs, i);

    vector<vector<int>> dp(n, vector<int>(E + 1, -1));

    int maxProfit = getMaxProfit(jobs, n - 1, E, dp, p);

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}