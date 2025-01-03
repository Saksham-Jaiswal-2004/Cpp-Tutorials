#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    int num1,num2;

    cout<<"Enter value of num1:\n" ; // '<<' is called Insertion Operator 
    cin>>num1; //Taking input from user and storing it in num1

    cout<<"Enter value of num2:\n" ; //Insertion Operator 
    cin>>num2; //'>>' is called Extraction Operator. Taking input from user and storing it in num2

    cout<<"Sum of num1 and num2 = "<<(num1+num2);
    cout<<"\n";
    Sleep(1000);
    cout<<"Difference of num1 and num2 = "<<(abs(num1-num2));
    cout<<"\n";
    Sleep(1000);
    cout<<"Product of num1 and num2 = "<<(num1*num2);
    cout<<"\n";

    return 0;
}