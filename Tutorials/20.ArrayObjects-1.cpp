#include<iostream>

using namespace std;

class Employee // It's like defining a data type 'Employee'
{
    int id;
    int salary;
    public:
      void setId(void)
      {
        salary = 122;
        cout<<"Enter ID of Employee: ";
        cin>>id;
      }

      void getId(void)
      {
        cout<<"The ID of employee is: "<<id<<endl;
      }
};

int main()
{
    // Employee Saurabh, Rohit, Raushan, Sayan;
    // Saurabh.setId();
    // Saurabh.getId();

    int n=10;
    Employee FOSS[n];

    for(int i=0 ; i<n ; i++)
    {
        FOSS[i].setId();
    }
    for(int i=0 ; i<n ; i++)
    {
        FOSS[i].getId();
    }

    return 0;
}