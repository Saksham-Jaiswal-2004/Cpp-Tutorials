#include<iostream>
#include<stdlib.h>
using namespace std;

int c = 24083;

int main()
{
    // **********Built in Data Types**********
    int a,b,c;

    cout<<"Enter Value of a:"<<endl;
    cin>>a;
    cout<<"Enter Value of b:"<<endl;
    cin>>b;
    c = a+b;
    cout<<"Sum of a and b = "<<c<<endl;

    cout<<"Value of Global c = "<<::c<<endl; // '::' -> Scope Resolution Operator → Fethces global variables and entities or variable outside current scope

    // **********Reference Variables**********
    float x = 455;
    float & y = x; //y becomes a reference variable pointing x
    cout<<"Value of x: "<<x<<endl;
    cout<<"Value of y: "<<y<<endl;

    // **********Type Casting**********
    float d = 45.46;
    cout<<"Value of float d: "<<d<<endl;
    cout<<"Value of int d: "<<(int)d<<endl;
    cout<<"Value of int d: "<<int(d)<<endl;

    // system("cls");

    return 0;
}