#include<iostream>
#include<math.h>

#define max 10

using namespace std;

struct Stack
{
    int top;
    int array[max];

    void initialize()
    {
        top = -1;
    }
    bool isEmpty()
    {
        if(top == -1)
        return true;
        else
        return false;
    }
    void push(int data)
    {
        top += 1;
        array[top] = data;
    }
    int pop()
    {
        if(isEmpty())
        return -1;
        else
        return array[top--];
    }
    void printStack(char name)
    {
        cout<<name<<": ";
        if(isEmpty())
        {
            cout<<"(Empty)";
        }
        else
        {
            for(int i=0 ; i<=top ; i++)
            {
                cout<<array[i]<<" ";
            }
        }
        cout<<endl;
    }
};

void printStacks(Stack &Source, Stack &Auxiliary, Stack &Destination, char s, char a, char d)
{
    cout<<"Current state of stacks: "<<endl;
    Source.printStack(s);
    Auxiliary.printStack(a);
    Destination.printStack(d);
    cout<<"--------------------------"<<endl;
}

void moveDisk(Stack &source, Stack &destination, char s, char d)
{
    int disk1 = source.pop();
    int disk2 = destination.pop();

    if(disk1==-1)
    {
        source.push(disk2);
        cout<<"Moved disk "<<disk2<<" from "<<d<<" to "<<s<<endl;
    }
    else if(disk2==-1)
    {
        destination.push(disk1);
        cout<<"Moved disk "<<disk1<<" from "<<s<<" to "<<d<<endl;
    }
    else if(disk1>disk2)
    {
        source.push(disk1);
        source.push(disk2);
        cout<<"Moved disk "<<disk2<<" from "<<d<<" to "<<s<<endl;
    }
    else
    {
        destination.push(disk2);
        destination.push(disk1);
        cout<<"Moved disk "<<disk1<<" from "<<s<<" to "<<d<<endl;
    }
}

void towerOfHanoi(int n, bool rep)
{
    int moves = (int)pow(2,n)-1;
    cout<<"Total steps: "<<moves<<endl;
    Stack Source, Auxiliary, Destination;
    char s='A', a='B', d='C';

    Source.initialize();
    Auxiliary.initialize();
    Destination.initialize();

    for(int i=n ; i>=1 ; i--)
    {
        Source.push(i);
    }

    if(n%2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }

    if(rep)
    {
        if(n%2==0)
        printStacks(Source, Destination, Auxiliary, s, d, a);
        else
        printStacks(Source, Auxiliary, Destination, s, a, d);
    }

    for(int i=1 ; i<=moves ; i++)
    {
        if(i%3==1)
        moveDisk(Source, Destination, s, d);
        else if(i%3==2)
        moveDisk(Source, Auxiliary, s, a);
        else if(i%3==0)
        moveDisk(Auxiliary, Destination, a, d);

        if(rep)
        {
            if(n%2==0)
            printStacks(Source, Destination, Auxiliary, s, d, a);
            else
            printStacks(Source, Auxiliary, Destination, s, a, d);
        }
    }
}

int main()
{
    int disks, counter;
    cout<<"Enter number of disks: ";
    cin>>disks;
    cout<<"Do you want representation of each step as well? (1=yes): ";
    cin>>counter;

    if(counter==1)
    towerOfHanoi(disks, true);
    else
    towerOfHanoi(disks, false);
    return 0;
}