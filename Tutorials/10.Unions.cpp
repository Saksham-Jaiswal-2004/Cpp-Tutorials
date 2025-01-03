#include<iostream>

using namespace std;

union money
{
    /* data */
    int rice;
    char car;
    float pounds;
};

int main()
{
    union money m1;

    m1.rice = 34;
    cout<<m1.rice<<endl;
    return 0;
}

// Unions are like structures but they provide better memory management.
// While using union we can only use one variable at a time.