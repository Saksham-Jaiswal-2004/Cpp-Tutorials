#include<iostream>
#include<time.h>

using namespace std;

class Node
{
    public:
    int val;
    Node* next;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
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

Node* addTwoNumbers(Node* l1, Node* l2) 
{
    Node* temp1 = l1;        
    Node* temp2 = l2;

    Node* ans = new Node(0);
    Node* start = ans;

    int sum=0, carry=0, digit=0;     

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1!=NULL && temp2!=NULL)
        sum = temp1->val + temp2->val + carry;
        else if(temp2!=NULL)
        sum = temp2->val + carry;
        else
        sum = temp1->val + carry;

        carry = sum/10;
        digit = sum%10;

        Node* a = new Node(digit);
        ans->val = a->val;
        if(temp1->next!=NULL || temp2->next!=NULL || carry!=0)
        {
            ans->next = a;
            ans = a;
        }
        
        cout<<digit<<" ";
        if(temp1!=NULL)
        temp1 = temp1->next;
        if(temp2!=NULL)
        temp2 = temp2->next;
    }

    while(temp1!=NULL)
    {
        sum = temp1->val + carry;
        carry = sum/10;
        digit = sum%10;

        Node* a = new Node(digit);
        ans->val = a->val;
        if(temp1->next!=NULL || carry!=0)
        {
            ans->next = a;
            ans = a;
        }

        cout<<digit<<" ";
        temp1 = temp1->next;
    }

    while(temp2!=NULL)
    {
        sum = temp2->val + carry;
        carry = sum/10;
        digit = sum%10;

        Node* a = new Node(digit);
        ans->val = a->val;
        if(temp2->next!=NULL || carry!=0)
        {
            ans->next = a;
            ans = a;
        }

        cout<<digit<<" ";
        temp2 = temp2->next;
    }

    if(carry!=0)
    {
        cout<<carry;
        Node* a = new Node(carry);
        ans->val = a->val;
    }

    return start;
}

void printList(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    srand(time(0));
    Node* node1 = new Node(5);
    Node* node2 = new Node(5);

    Node* head1 = node1;
    Node* tail1 = node1;

    Node* head2 = node2;
    Node* tail2 = node2;

    for(int i=0 ; i<6 ; i++)
    {
        int num = rand() % (9 - 1 + 1) + 1;
        // insertAtTail(tail1, num);
        // insertAtTail(tail1, 9);
    }

    for(int i=0 ; i<3 ; i++)
    {
        int num = rand() % (9 - 1 + 1) + 1;
        // insertAtTail(tail2, num);
        // insertAtTail(tail2, 9);
    }

    cout<<"Original Linked List 1: "<<endl;
    printList(head1);

    cout<<endl;

    cout<<"Original Linked List 2: "<<endl;
    printList(head2);

    cout<<endl;

    Node* a = addTwoNumbers(head1, head2);

    cout<<endl;

    printList(a);

    return 0;
}