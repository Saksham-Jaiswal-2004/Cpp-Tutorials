#include<iostream>

using namespace std;

class Employee{
    private:
      int a, b, c;

    public:
      int d, e;
      void setData(int a, int b, int c);// Class ke andar function prototype likh ke declare krdiye baad me iska code likhenge
      void getData()
      {
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
        cout<<"The value of c is "<<c<<endl;
        cout<<"The value of d is "<<d<<endl;
        cout<<"The value of e is "<<e<<endl;
      }
};

void Employee :: setData(int a1, int b1, int c1) //Writing setData function
{
    a = a1;
    b = b1;
    c = c1;
}

int main()
{
    Employee Saksham;// Creating an object of Employee class
    Saksham.d = 12;
    Saksham.e = 34;
    Saksham.setData(1, 6, 8);
    Saksham.getData();

    return 0;
}