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

Node* removeNthFromEnd(Node* head, int n)
{
    Node* temp = head;
    int len=0;

    if(!head)
    return NULL;

    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }

    if(n>len)
    return NULL;

    temp = head;
    for(int i=0 ; i<len-n-1 ; i++)
    {
        temp = temp->next;
    }

    if(len==n)
    {
        temp = head;
        head = head->next;
        temp->next = nullptr;
        return head;
    }

    temp->next = temp->next->next;

    return head;
}

int main()
{
    int data[] = {6,2,4,7,5,8,1,9};
    Node* head = new Node(3);
    int k;
    
    Node* temp = head;
    for(int i: data)
    {
        Node* newNode = new Node(i);
        temp->next = newNode;
        temp = newNode;
    }

    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    cout<<"Select Node to remove from end: ";
    cin>>k;
    
    temp = removeNthFromEnd(head, k);
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    return 0;
}