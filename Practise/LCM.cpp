#include<iostream>

using namespace std;

int gcd(int min, int num1, int num2)
{
    int ans=-1;
    for(int i=1 ; i<=min/2 ; i++)
    {
        if(num1%i==0 && num2%i==0)
        {
            ans = i;
        }
    }

    return ans;
}

int main()
{
    int n1, n2, min;

    cout<<"Enter first number: ";
    cin>>n1;
    cout<<"Enter second number: ";
    cin>>n2;

    if(n1>n2)
    {
        min=n2;
    }
    else
    {
        min=n1;
    }

    int lcm = (n1/gcd(min, n1, n2))*n2;

    cout<<"LCM of "<<n1<<" and "<<n2<<" is: "<<lcm<<endl;
    return 0;
}