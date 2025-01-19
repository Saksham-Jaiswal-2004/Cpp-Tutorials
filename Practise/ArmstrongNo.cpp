#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n, sum=0;

    cout<<"Enter number to be checked: ";
    cin>>n;

    string n1 = to_string(n);
    int len = n1.length();

    int copy=n;
    while(copy>0)
    {
        int a=copy%10;
        sum += (int)pow(a,len);
        copy/=10;
    }

    if(sum==n)
    {
        cout<<n<<" is an Armstrong Number!"<<endl;
    }
    else
    {
        cout<<n<<" is not an Armstrong Number!"<<endl;
    }
    return 0;
}