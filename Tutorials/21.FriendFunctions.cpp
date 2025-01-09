// A friend class can access private and protected members of other classes in which it is declared as a friend.
// It is sometimes useful to allow a particular class to access private and protected members of other classes.

// Like a friend class, a friend function can be granted special access to private and protected members of a 
// class in C++. They are not the member functions of the class but can access and manipulate the private and 
// protected members of that class for they are declared as friends.
#include<iostream>

using namespace std;

class complex
{
    int a,b;
    public:
      void setNumber(int n1, int n2)
      {
        a = n1;
        b = n2;
      }
      void printNumber()
      {
        cout<<"Your complex number is: "<<a<<" + "<<b<<"i"<<endl;
      }

    //  Setting sumComplex as the friend function of complex class so that it can access it's private variables and other data
      friend complex sumComplex(complex o1, complex o2);
};

complex sumComplex(complex o1, complex o2)
{
    complex o3;
    o3.setNumber(o1.a + o2.a, o1.b + o2.b);
    return o3;
}

int main()
{
    complex c1, c2, sum;
    c1.setNumber(1,4);
    c2.setNumber(5,8);
    c1.printNumber();
    c2.printNumber();

    cout<<"Sum of above two complex numbers is: "<<endl;
    sum = sumComplex(c1, c2);
    sum.printNumber();

    return 0;
}
/*
Properties of friend functions:
1.It is not in the scope of class.
2.As it is not in the scope of the class so it cannot be called from the abject of that class.
3.It can be invoked without the help of any object.
4.It usually have objects as its arguments (Not Necessarily).
5.It can be declared both in the public and private section of the class.
6.It cannot access the members directly by their names, it is done as - objectName.memberName, to access any member.
*/ 