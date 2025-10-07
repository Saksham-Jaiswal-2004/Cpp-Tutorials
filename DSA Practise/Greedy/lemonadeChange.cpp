#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool lemonadeChange(vector<int>& bills)
{
    int min = 0;
    int min2 = 0;
    bool flag = true;

    for(int i=0 ; i<bills.size() ; i++)
    {
        if(bills[i] == 5)
        {
            min++;
        }
        else if(bills[i] == 10)
        {
            if(min>0)
            {
                min--;
                min2++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        else
        {
            if(min>0 && min2>0)
            {
                min--;
                min2--;
            }
            else if(min2==0 && min>2)
            {
                min-=3;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    vector<int> bills = {5,5,5,5,20,20,5,5,5,5};
    cout<<lemonadeChange(bills)<<endl;

    return 0;
}