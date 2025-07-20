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
};

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

// Approach 1
// Use Map
bool detectLoop(Node* head)
{
    if(head == NULL)
    return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp!=NULL)
    {
        if(visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// Approach 2
// Floyd's Cycle Detection Algorithm
bool floyd(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    if(head == NULL)
    return false;

    if(head->next == NULL)
    return false;

    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow==fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    Node* head = new Node(1);
    Node* temp = head;

    for(int i=0 ; i<9 ; i++)
    {
        Node* newNode = new Node(i+2);
        temp->next = newNode;
        temp = newNode;
    }

    printList(head);
    temp->next = head;
    temp = head;

    for(int i=0 ; i<1 ; i++)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;

    if(detectLoop(head))
    cout<<"There's a Loop."<<endl;
    else
    cout<<"No Loop."<<endl;

    if(floyd(head))
    cout<<"There's a Loop."<<endl;
    else
    cout<<"No Loop."<<endl;
    return 0;
}