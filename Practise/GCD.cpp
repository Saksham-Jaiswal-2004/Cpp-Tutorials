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
    int n1, n2;
    int ans;

    cout<<"Enter first number: ";
    cin>>n1;
    cout<<"Enter second number: ";
    cin>>n2;

    if(n1>n2)
    {
        ans = gcd(n2, n1, n2);
    }
    else
    {
        ans = gcd(n1, n1, n2);
    }

    if(ans==-1)
    {
        cout<<"No Common Divisor."<<endl;
    }
    else
    {
        cout<<"GCD of "<<n1<<" and "<<n2<<" is: "<<ans<<endl;
    }

    return 0;
}