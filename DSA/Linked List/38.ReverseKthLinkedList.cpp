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

int length(Node* head)
{
    int len=0;
    Node* temp = head;

    while(temp!=NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

Node* reverseKGroup(Node* &head, int k)
{
    Node* temp = head;
    Node* previous = head;
    Node* current = head;
    Node* forward = head->next;

    int num = length(head)/k;
    int num2 = length(head)%k;

    for(int j=0 ; j<num ; j++)
    {
        for(int i=0 ; i<k*(j+1) ; i++)
        {
            previous = previous->next;
        }
        for(int i=0 ; i<k*j ; i++)
        {
            head = head->next;
        }
        forward = head->next;

        for(int i=0 ; i<k ; i++)
        {
            current->next = previous;
            if(i!=k-1)
            {
                previous = current;
                current = forward;
            }
            
            if(current!=NULL)
            head = current;

            if(forward!=NULL)
            forward = forward->next;
        }
        cout<<endl;
    }

    return head;
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

    for(int i=0 ; i<9 ; i++)
    {
        int num = rand() % (100 - 1 + 1) + 1;
        insertAtTail(tail, num);
    }

    cout<<"Original Linked List: "<<endl;
    printList(head);

    cout<<endl;

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    cout<<endl;

    printList(reverseKGroup(head, 3));

    cout<<endl;

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    return 0;
}