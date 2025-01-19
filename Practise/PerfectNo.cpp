// A Perfect number is a number which is equal to the sum of its positive divisors excluding itself
#include<iostream>

using namespace std;

int main()
{
    int n,sum=0;

    cout<<"Enter number to be checked: ";
    cin>>n;

    for(int i=1 ; i<=n/2 ; i++)
    {
        if(n%i==0)
        {
            sum += i;
        }
    }

    // cout<<"Sum: "<<sum<<endl;

    if(sum==n)
    {
        cout<<n<<" is a Perfect Number!"<<endl;
    }
    else
    {
        cout<<n<<" is not a Perfect Number!"<<endl;
    }
    return 0;
}