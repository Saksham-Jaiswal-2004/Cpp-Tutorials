#include<iostream>

using namespace std;

class Node //Class
{
    public:
    int data;
    Node* next;

    Node(int data) //Constructor
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* reverse(Node* mid)
{
    Node* previous = NULL;
    Node* current = mid;
    Node* forward = current->next;
    if(current!=NULL)
    forward = current->next;

    while(current!=NULL)
    {
        current->next = previous;
        previous = current;
        current = forward;

        if(forward!=NULL)
        forward = forward->next;
    }
    
    return previous;
}

bool isPalindrome(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL)
        fast = fast->next;
    }

    slow = reverse(slow);
    fast = head;

    while(slow!=NULL && fast!=NULL)
    {   
        if(slow->data != fast->data)
        return false;
        
        slow = slow->next;
        fast = fast->next;
    }

    return true;
}

int main()
{
    int data[] = {1,4,3,3,2,1};
    int data2[] = {1,2,3,4,3,2,1};
    Node* head = new Node(data[0]);
    Node* temp = head;

    for(int i=0 ; i<5 ; i++)
    {
        Node* newNode = new Node(data[i+1]);
        temp->next = newNode;
        temp = newNode;
    }
    temp = head;

    for(int i=0 ; i<6 ; i++)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;

    if(isPalindrome(head))
    cout<<"Palindrome"<<endl;
    else
    cout<<"Not Palindrome"<<endl;

    return 0;
}