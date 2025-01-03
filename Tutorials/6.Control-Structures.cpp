#include<iostream>

using namespace std;

int main()
{
    int age;

    cout<<"Tell me your age:"<<endl;
    cin>>age;

    cout<<"Age: "<<age<<endl;

    if(age<18 && age>0)
    {
        cout<<"You are too young to enter the party."<<endl;
    }
    else if(age>=18 && age<30)
    {
        cout<<"You can enter the party."<<endl;
    }
    else if(age<=0)
    {
        cout<<"You are not yet born."<<endl;
    }
    else
    {
        cout<<"You are too old to enter the party."<<endl;
    }
}

// C++ Control Structures:
// 1. Sequence Structure
// 2. Selection Structure
// 3. Loop Structure

// 1. Sequence Structure 
// Entry → Action 1 → Action 2 → Exit

// 2. Selection Structure
// Entry → If true - Action 1 → Else - Action 2 → Exit

// 3. Loop Structure
// Entry → If True - Action 1 → Again condition will be looped until it becomes false Action 1 will be executed → Exit

// (a) if-else statement
// (b) if-else ladder
// (c) switch case