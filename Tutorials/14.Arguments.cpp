// Jab boht kam function use ho rha ho tabhi inline fucntions use krna hai else boht CPU space lelega jo program slow krdega.

// When not to use Inline Functions:
// 1. When using Recursion
// 2. When working withh static variables
// 3. When using loops
// 4. When using switch cases
#include<iostream>

using namespace std;

// An inline function is a function that is expanded in line when it is called.
// When the inline function is called whole code of the inline function gets inserted or substituted at the 
// point of the inline function call.
inline int product(int a, int b)
{
    return a*b;
}

float moneyReceived(int currentMoney, float factor=1.04) // Here, for the second argument if nothing is passed then it will take the default value of 1.04
{
    return currentMoney*factor;
}

int main()
{
    int m,n,money;

    // cout<<"Enter Value of a and b:"<<endl;
    // cin>>m>>n;
    // cout<<"Product: "<<product(m,n)<<endl;

    cout<<"Enter money you have:"<<endl;
    cin>>money;
    cout<<"After 10 years you will receive "<<moneyReceived(money)<<" if you have "<<money<<endl;
    cout<<"After 10 years you will receive "<<moneyReceived(money,2)<<" if you are a VIP and have "<<money<<endl;
    
    return 0;
}