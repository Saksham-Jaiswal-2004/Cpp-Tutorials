#include<iostream>
#include<math.h>

#define MAX 10

using namespace std;

// Defining Stack to implement Tower of Hanoi
struct Stack
{
    int top;
    int arr[MAX];
    void init()
    {
        top = -1; 
    }
    bool isEmpty() 
    { 
        return top == -1; 
    }
    void push(int item) 
    { 
        arr[++top] = item; 
    }
    int pop() 
    { 
        return (isEmpty()) ? -1 : arr[top--]; 
    }
    void printStack(char name)
    {
        cout<<name<<": ";
        if (isEmpty()) 
        {
            cout<<"(Empty)";
        } 
        else 
        {
            for (int i = 0; i <= top; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
};

// Function to print the state of all three stacks
void printStacks(Stack &Source, Stack &Auxiliary, Stack &Destination, char s, char a, char d) 
{
    cout << "Current State of Stacks:" << endl;
    Source.printStack(s);
    Auxiliary.printStack(a);
    Destination.printStack(d);
    cout << "-------------------------" << endl;
}

// Function to move disks between three pegs
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
    else if(disk1 > disk2)
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

// Function to implement the main logic of Tower of Hanoi
void towerOfHanoi(int n, bool counter)
{
    cout<<"Number of disks for Tower of Hanoi: "<<n<<endl;
    int moves = (int)pow(2, n) - 1;
    cout<<"Number of moves to solve Tower of Hanoi: "<<moves<<endl;

    Stack Source, Auxiliary, Destination;
    char s='A', a='B', d='C';

    Source.init();
    Auxiliary.init();
    Destination.init();

    for (int i = n; i >= 1; i--) 
    {
        Source.push(i);
    }

    if(n%2==0)
    {
        char temp = d;
        d = a;
        a = temp;
    }

    if(counter)
    {
        if(n%2==0)
        printStacks(Source, Destination, Auxiliary, s, d, a);
        else
        printStacks(Source, Auxiliary, Destination, s, a, d);
    }

    for(int i=1 ; i<=moves ; i++)
    {
        cout<<endl;
        if(i%3==1)
          moveDisk(Source, Destination, s, d);
        else if(i%3==2)
          moveDisk(Source, Auxiliary, s, a);
        else if(i%3==0)
          moveDisk(Auxiliary, Destination, a, d);

        if(counter)
        {
            if(n%2==0)
            printStacks(Source, Destination, Auxiliary, s, d, a);
            else
            printStacks(Source, Auxiliary, Destination, s, a, d);
        }
    }
}

// Main function
int main()
{
    int disks, rep, max=10;
    cout<<"Enter Number of disks: ";
    cin>>disks;

    if(disks>max)
    {
        cout<<"Max number of disks can be "<<max<<endl;
        return -1;
    }

    cout<<"Do you want representation as well?"<<endl;
    cout<<"1 = Yes, Anything Else = No: ";
    cin>>rep;

    if(rep==1)
    towerOfHanoi(disks, true);
    else
    towerOfHanoi(disks, false);

    return 0;
}