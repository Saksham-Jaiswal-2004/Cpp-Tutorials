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

Node* headOfLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    int counter = 1;

    if(head==NULL || head->next==NULL)
    return NULL;

    while(slow!=NULL && fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL && counter==1)
        fast = fast->next;

        if(slow==fast && counter==1)
        {
            cout<<"Loop present!"<<endl;
            slow = head;
            counter = 0;
        }

        if(slow==fast && counter==0)
        {
            return slow;
        }
    }
    return NULL;
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

    temp->next = head->next->next;
    temp = head;

    for(int i=0 ; i<11 ; i++)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    Node* res = headOfLoop(head);
    cout<<"Head of Loop: "<<res->data<<endl;
    return 0;
}