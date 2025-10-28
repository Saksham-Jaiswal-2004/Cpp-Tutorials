#include <bits/stdc++.h>
using namespace std;

int coinChangeMinCoins(const vector<int>& coins, int Val, vector<int>& usedCoin) 
{
    const int INF = 1e9;
    vector<int> dp(Val + 1, INF);
    usedCoin.assign(Val + 1, -1); // store index of coin used to reach amount

    dp[0] = 0; // zero coins to make amount 0

    for (int x = 1; x <= Val; ++x) 
    {
        for (int i = 0; i < (int)coins.size(); ++i) 
        {
            int c = coins[i];
            if (c <= x && dp[x - c] != INF) 
            {
                if (dp[x - c] + 1 < dp[x]) 
                {
                    dp[x] = dp[x - c] + 1;
                    usedCoin[x] = i; // coin index i used to reach x
                }
            }
        }
    }

    return dp[Val] == INF ? -1 : dp[Val];
}

vector<int> reconstructCoins(const vector<int>& coins, const vector<int>& usedCoin, int Val) 
{
    vector<int> res;
    if (Val <= 0) return res;
    int cur = Val;
    while (cur > 0 && usedCoin[cur] != -1) 
    {
        int idx = usedCoin[cur];
        res.push_back(coins[idx]);
        cur -= coins[idx];
    }
    if (cur != 0) 
    {
        // reconstruction failed (amount not reachable)
        return {};
    }
    return res; // coins in reverse order (from Val down)
}

int main() 
{
    int N;
    cout << "Enter number of coin types (N): ";
    if (!(cin >> N) || N <= 0) 
    {
        cerr << "Invalid N\n";
        return 0;
    }

    vector<int> coins(N);
    cout << "Enter " << N << " coin denominations:\n";
    for (int i = 0; i < N; ++i) cin >> coins[i];

    int Val;
    cout << "Enter target amount (Val): ";
    cin >> Val;
    if (Val < 0) 
    {
        cerr << "Invalid Val\n";
        return 0;
    }

    vector<int> usedCoin;
    int ans = coinChangeMinCoins(coins, Val, usedCoin);

    if (ans == -1) 
    {
        cout << "Not possible to make amount " << Val << " with given coins.\n";
    } 
    else 
    {
        cout << "Minimum number of coins required: " << ans << "\n";

        // optional: show one way to make the amount
        vector<int> way = reconstructCoins(coins, usedCoin, Val);
        if (!way.empty()) 
        {
            cout << "One combination of coins (order doesn't matter): ";
            for (int c : way) 
            cout << c << " ";
            
            cout << "\n";
        }
    }

    cout << "\nTime Complexity: O(N * Val)\nSpace Complexity: O(Val)\n";
    return 0;
}