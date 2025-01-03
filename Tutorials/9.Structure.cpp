#include<iostream>

using namespace std;

// struct Employee
// {
//     /* data */
//     int empId;
//     char favChar;
//     float salary;
// };

typedef struct Employee
{
    /* data */
    int empId;
    char favChar;
    float salary;
} ep;

int main()
{
    struct Employee saksham;
    ep rahul; //Same as above

    saksham.empId = 24083;
    saksham.favChar = 's';
    saksham.salary = 500000;

    cout<<saksham.empId<<endl;
    cout<<saksham.salary<<endl;
    return 0;
}