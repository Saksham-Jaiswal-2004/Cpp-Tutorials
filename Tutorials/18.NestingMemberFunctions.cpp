// Nesting of Member Functions

#include<iostream>
#include<string>

using namespace std;

class binary
{
    string s; // By default class members are private

    public:
      void read(void); // If we make any function private then it cannot be called from main function or any other function except the class functions or methods
      void chk_bin(void);
      void ones(void);
};

void binary :: read(void){
    cout<<"Enter a binary number:"<<endl;
    cin>>s;
};

void binary :: chk_bin(void){
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"Incorrect Binary Format."<<endl;
            exit(0);
        }
    }
    cout<<"Correct Binary Format."<<endl;
}

void binary :: ones(void){
    chk_bin();
    string com;
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s.at(i)=='0')
        {
            com += '1';
        }
        else
        {
            com += '0';
        }
    }
    cout<<"Complement of Entered Binary Number: "<<com;
}

int main()
{
    binary a;
    a.read();
    a.ones();
    // We can declare objects along with class declaration:
    /*class employee
    {
        // Class Definition;
    } Emp1, Emp2, Emp3;*/

    return 0;
}

// How Classes are different and better than Structures:
// 1. Classes can have public as well as private variables and functions whereas Structures can only have public members.
// 2. Classes can have methods and properties.