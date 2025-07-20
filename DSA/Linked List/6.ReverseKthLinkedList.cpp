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

int possible(Node* head, int k)
{
    Node* temp = head;
    int count = 0;

    for(int i=0 ; i<k ; i++)
    {
        if(temp!=NULL)
        {
            count++;
        }
        else
        {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

Node* reverseKGroup(Node* &head, int k)
{
    Node* temp;
    Node* tail = head;
    Node* previous = head;
    Node* current = head;
    Node* forward = head->next;

    if(k==1)
    return head;

    if(possible(head, k) && current!=NULL)
    {
        cout<<"Test 1"<<endl;
        for(int i=0 ; i<k ; i++)
        {
            previous = previous->next;
        }

        cout<<"Test 2"<<endl;
        for(int i=0 ; i<k ; i++)
        {
            temp = current;
            
            current->next = previous;
            previous = current;
            current = forward; 

            if(current->next != NULL)
            forward = current->next;
        }
        cout<<"Test 3"<<endl;

        cout<<"previous: "<<previous->data<<endl;
        cout<<"current: "<<current->data<<endl;
        cout<<"forward: "<<forward->data<<endl;
        
        if(current!=NULL)
        tail->next = reverseKGroup(current, k);
    }

    return previous;
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

    int len, k;

    cout<<"Enter length of Linked List: ";
    cin>>len;
    cout<<"Entered length: "<<len<<endl;
    cout<<"Enter length of groups to be reversed: ";
    cin>>k;

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    for(int i=0 ; i<len-1 ; i++)
    {
        int num = rand() % (100 - 1 + 1) + 1;
        insertAtTail(tail, num);
    }

    cout<<endl;
    cout<<"Original Linked List: "<<endl;
    printList(head);
    
    cout<<endl;
    
    cout<<"Reversed Linked List in group of "<<k<<": "<<endl;
    printList(reverseKGroup(head, k));

    cout<<endl;

    return 0;
}