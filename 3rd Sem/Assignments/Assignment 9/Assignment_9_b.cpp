#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int countWays(vector<int>& coins, int A) 
{
    vector<int> dp(A + 1, 0);
    dp[0] = 1;

    for (int coin : coins) 
    {
        for (int i = coin; i <= A; ++i) 
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[A];
}

int minCoins(vector<int>& coins, int A, vector<int>& parent) 
{
    vector<int> dp(A + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= A; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) 
            {
                if (dp[i] > dp[i - coin] + 1) 
                {
                    dp[i] = dp[i - coin] + 1;
                    parent[i] = coin; 
                }
            }
        }
    }

    return (dp[A] == INT_MAX) ? -1 : dp[A];
}

void printCombination(vector<int>& parent, int A) 
{
    if (parent[A] == -1) 
    {
        cout << "No combination found\n";
        return;
    }

    cout << "Combination: ";
    while (A > 0) 
    {
        cout << parent[A] << " ";
        A -= parent[A];
    }
    cout << endl;
}

int main() 
{
    int n, A;
    cout<<"Enter types of coins and maximum amount: ";
    cin >> n >> A;
    vector<int> coins(n);
    
    for (int i = 0; i < n; ++i) 
    {
        cout<<"Enter coin "<<i+1<<": ";
        cin >> coins[i];
    }

    cout << "Total ways: " << countWays(coins, A) << endl;

    vector<int> parent(A + 1, -1);
    int min_coin_count = minCoins(coins, A, parent);
    cout << "Minimum coins: " << min_coin_count << endl;

    if (min_coin_count != -1)
        printCombination(parent, A);

    return 0;
}