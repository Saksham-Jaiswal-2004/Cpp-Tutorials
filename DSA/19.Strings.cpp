#include<iostream>

using namespace std;

string reverse(string name, int len)
{
    int start=0;
    int end=len-1;
    string buffer = name;

    while(start<=end)
    {
        swap(buffer[start++], buffer[end--]);
    }

    return buffer;
}

int main()
{
    char name[20];
    char ch='a';
    int counter=0;
    cout<<"Enter your name: ";
    cin>>name;

    cout<<"Hello, "<<name<<endl;
    // name[2] = '\0';
    // cout<<"Hello, "<<name<<endl;

    while(ch!='\0')
    {
        ch = name[counter];
        counter++;
    }

    cout<<"Length of entered name: "<<counter-1<<endl;

    cout<<"Reversed String: "<<reverse(name, counter-1)<<endl;

    return 0;
}