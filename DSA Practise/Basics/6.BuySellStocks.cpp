#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    vector<int> data = prices;
    int minVal = data[0];
    int profit = 0;

    for(int i=0 ; i<data.size() ; i++)
    {
        if(minVal>data[i])
        minVal = data[i];

        if(data[i]-minVal > profit)
        profit = data[i] - minVal;
    }

    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    // vector<int> prices = {7,6,4,3,1};
    cout<<"Max Profit: "<<maxProfit(prices);

    return 0;
}