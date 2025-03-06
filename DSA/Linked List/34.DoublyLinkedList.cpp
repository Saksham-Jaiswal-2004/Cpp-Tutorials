#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAtHead(Node* &head, Node* &tail, int val)
{
    Node* temp = new Node(val);
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int val)
{
    Node* temp = new Node(val);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int val)
{
    Node* temp = new Node(val);
    Node* ref = head;

    if(pos==1)
    {
        insertAtHead(head, tail, val);
        return;
    }

    for(int i=1 ; i<pos-1 ; i++)
    {
        ref = ref->next;

        if(i!=pos-2 && ref->next==NULL)
        {
            cout<<"Error: Position "<<pos<<" out of bounds of Linked List!\n"<<endl;
            return;
        }
    }

    if(ref->next == NULL)
    {
        insertAtTail(tail, val);
        return;
    }

    temp->next = ref->next;
    temp->prev = ref;
    ref->next->prev = temp;
    ref->next = temp;
}

void deleteNode(Node* &head, int pos)
{
    if(pos==1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* current = head;
        Node* previous = NULL;

        int count = 1;
        while(count<pos)
        {
            previous = current;
            current = current->next;
            count++;
        }
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;

        delete current;
    }
}

void display(Node* head)
{
    Node* temp = head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* head)
{
    int len=0;
    Node* temp = head;

    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

int main()
{
    Node* node1 = new Node(45);
    Node* head = node1;
    Node* tail = node1;

    display(head);
    cout<<endl;

    insertAtHead(head, tail, 36);
    insertAtHead(head, tail, 27);
    insertAtHead(head, tail, 19);
    insertAtHead(head, tail, 12);

    display(head);
    cout<<endl;

    insertAtTail(tail, 56);
    insertAtTail(tail, 62);
    insertAtTail(tail, 78);
    insertAtTail(tail, 83);

    display(head);
    cout<<endl;

    insertAtPosition(head, tail, 3, 99);
    insertAtPosition(head, tail, 5, 100);
    insertAtPosition(head, tail, 1, 200);
    insertAtPosition(head, tail, 13, 300);

    display(head);
    cout<<endl;

    cout<<"Length: "<<getLength(head)<<endl;

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    deleteNode(head, 5);
    deleteNode(head, 1);

    cout<<endl;
    display(head);
    cout<<endl;

    cout<<"\nLength: "<<getLength(head)<<endl;

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    return 0;
}