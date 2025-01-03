// Using functions in C++
#include<iostream>

using namespace std;

int sum(int a, int b); //Method 1
//int sum(int, int); //Method 2

int main()
{
    int n1, n2;

    cout<<"Enter first number:"<<endl;
    cin>>n1;
    cout<<"Enter second number:"<<endl;
    cin>>n2;

    cout<<"The sum of "<<n1<<" and "<<n2<<" is: "<<sum(n1, n2)<<endl;

    return 0;
}

int sum(int a, int b)
{
    int c = a+b;
    return c;
}