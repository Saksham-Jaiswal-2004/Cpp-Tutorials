#include<iostream>

using namespace std;

int fact(int num);
int fib(int n);

int main()
{
    int a,b;
    cout<<"Enter Number to get its factorial:";
    cin>>a;
    cout<<"Factorial of "<<a<<" : "<<fact(a)<<endl;

    cout<<"Enter number of terms for Fibonacci series:";
    cin>>b;

    cout<<"Fibonacci Series till "<<b<<" terms:"<<endl;
    for(int i=1 ; i<=b ; i++)
    {
        cout<<fib(i)<<" ";
    }

    return 0;
}

int fact(int num)
{
    if(num<=1)
    {
        return 1;
    }
    return num*fact(num-1);
}

int fib(int n)
{
    if(n<2)
    {
        return 1;
    }
    return fib(n-2) + fib(n-1);
}