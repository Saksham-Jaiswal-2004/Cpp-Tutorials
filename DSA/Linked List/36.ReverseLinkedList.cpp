#include<iostream>
#include<bits/stdc++.h>

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

    ~Node() //Destructor
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "\nMemory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int val)
{
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int val)
{
    Node* temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

int insertAtMiddle(Node* &head, Node* &tail, int pos, int val)
{
    Node* temp = new Node(val);
    Node* ref = head;

    if(pos==1)
    {
        insertAtHead(head, val);
        return 1;
    }
    
    for(int i=1 ; i<pos-1 ; i++)
    {
        ref = ref->next;

        if(i!=pos-2 && ref->next==NULL)
        {
            cout<<"\nError: Index "<<pos<<" out of bounds of Linked List!"<<endl;
            return 0;
        }
    }

    if(ref->next==NULL)
    {
        insertAtTail(tail, val);
        return 1;
    }

    temp->next = ref->next;
    ref->next = temp;

    return 1;
}

void deleteNode(Node* & head, int pos) 
{ 

    //deleting first or start node
    if(pos == 1) 
    {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos) 
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

void reverse(Node* &head, Node* &tail)
{
    Node* previous = NULL;
    Node* current = head;
    Node* nextNode = head->next;
    tail = head;

    while(current!=NULL)
    {
        current->next = previous;
        previous = current;
        head = current;
        current = nextNode;
        if(nextNode!=NULL)
        nextNode = nextNode->next;
    }
    cout<<"Done Reversing!"<<endl;
}

void reverse2(Node* &head, Node* current, Node* previous) //Using Recursion
{
    if(current==NULL)
    {
        head = previous;
        return;
    }

    Node* forward = current->next;
    reverse2(head, forward, current);
    current->next = previous;
}

void printList(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    srand(time(0));
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    for(int i=0 ; i<10 ; i++)
    {
        int num = rand() % (100 - 1 + 1) + 1;
        insertAtTail(tail, num);
    }

    cout<<"Original Linked List: "<<endl;
    printList(head);
    cout<<"\nHead: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    cout<<endl;
    reverse(head, tail);

    cout<<"Reversed Linked List: "<<endl;
    printList(head);
    cout<<"\nHead: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    
    return 0;
}