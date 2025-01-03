#include<iostream>
#include<windows.h>

using namespace std;

int main()
{
    system("cls");

    int a = 3;
    int *b = &a; //Pointer
    int **c = &b; //Pointer to pointer

    cout<<"Value of a: "<<a<<endl;
    cout<<"Value of a: "<<*b<<endl;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Address of a: "<<b<<endl;
    cout<<"Value of b: "<<*c<<endl;
    cout<<"Address of b: "<<c<<endl;
    
    return 0;
}

// Pointers → It's a data type that holds the address of other data types
// & → (Address of) operator
// * → (Value at) Dereference operator