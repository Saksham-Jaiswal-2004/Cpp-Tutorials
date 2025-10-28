#include<iostream>
#include<vector>

using namespace std;

int weight(vector<int>& coins, int a, int b)
{
    int sum=0;

    for(int i=a ; i<=b ; i++)
    sum += coins[i];

    return sum;
}

int fakeIndex(vector<int>& coins, int a, int b)
{
    int start=a, end=b;
    int mid = start + (end-start)/2;

    if(coins.size()%2!=0)
    start++;

    while(coins.size()>2 && start<end)
    {
        int left = weight(coins, start, mid);
        int right = weight(coins, mid+1, end);

        if(left==right)
        {
            if(coins.size()%2!=0)
            {
                if(coins[0]<coins[1])
                return 0;
            }
            return -1;
        }
        else if(left<right)
        return fakeIndex(coins, start, mid);
        else
        return fakeIndex(coins, mid+1, end);
    }

    if(coins[a]>coins[b])
    return b;
    else
    return a;
}

int main()
{
    vector<int> coins = {2,2,2,2,2,2,2,2,2,1,2};

    int pos = fakeIndex(coins,0,coins.size()-1);

    if(pos==-1)
    cout<<"No Fake coins in the lot!"<<endl;
    else
    cout<<"Fake coin at index: "<<pos<<endl;

    return 0;
}