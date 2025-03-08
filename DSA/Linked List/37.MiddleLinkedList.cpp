#include<iostream>
#include<time.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
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

Node* findMiddle(Node* head)
{
    Node* a = head;
    Node* b = head;
    Node* c = head;
    int len = 0;

    while(b->next!=NULL && b->next->next!=NULL)
    {
        a = a->next;
        b = b->next->next;
    }

    while(c!=NULL)
    {
        len++;
        c = c->next;
    }

    if(len%2!=0)
    return a;
    else
    return a->next;
}

void printList(Node* head)
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

    for(int i=0 ; i<5 ; i++)
    {
        int num = rand() % (100 - 1 + 1) + 1;
        insertAtTail(tail, num);
    }

    cout<<"Original Linked List: "<<endl;
    printList(head);

    cout<<endl;

    cout<<"After Middle of Linked List: "<<endl;
    printList(findMiddle(head));

    return 0;
}