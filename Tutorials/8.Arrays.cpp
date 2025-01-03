#include<iostream>
#include<ctime>

using namespace std;

int main()
{
    //Arrays
    srand(time(0));
    int marks[5];

    for(int i=0 ; i<5 ; i++)
    {
        // cout<<"Enter marks of student "<<(i+1)<<":";
        // cin>>marks[i];
        marks[i] = (rand() % 100) + 1;
    }

    cout<<endl;
    for(int i=0 ; i<5 ; i++)
    {
        cout<<"Marks of student "<<(i+1)<<": "<<marks[i]<<endl;
    }

    cout<<endl;
    cout<<"Address val-primary: "<<&marks<<endl;
    cout<<"Address val-1: "<<&marks[0]<<endl;
    cout<<"Address val-2: "<<&marks[1]<<endl;

    //Pointers with Arrays
    cout<<endl;
    int *p = marks;
    cout<<"Value 1: "<<p<<endl;
    cout<<"Value 2: "<<(p+1)<<endl;
    cout<<"Value 3: "<<(p+2)<<endl;
    cout<<"Value 4: "<<(p+3)<<endl;
    cout<<"Value 5: "<<(p+4)<<endl;

    //Pointer Arithmetic
    //New Address = Old Address + (i * sizeof(data type));
    

    return 0;
}