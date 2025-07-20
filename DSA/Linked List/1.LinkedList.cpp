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
    Node* node1 = new Node(10); //Making object of class
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;

    cout<<"Initial Linked List:"<<endl;
    printList(head);

    for(int i=0 ; i<5 ; i++)
    {
        insertAtHead(head, i+15);
    }

    cout<<"\nLinked List after Inserting at Head:"<<endl;
    printList(head);

    insertAtMiddle(head, tail, 3, 9);

    cout<<"\nLinked List after Inserting at 3rd position:"<<endl;
    printList(head);

    insertAtMiddle(head, tail, 1, 65);

    cout<<"\nLinked List after Inserting at 1st position:"<<endl;
    printList(head);

    int flag = insertAtMiddle(head, tail, 60, 500);

    if(flag)
    {
        cout<<"\nLinked List after Inserting at 60th position:"<<endl;
        printList(head);
    }

    for(int i=0 ; i<5 ; i++)
    {
        insertAtTail(tail, i+26);
    }

    cout<<"\nLinked List after Inserting at Tail:"<<endl;
    printList(head);

    deleteNode(head, 13);

    cout<<"\nLinked List after Deleting at 13th position:"<<endl;
    printList(head);

    cout<<"\nHead: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    
    return 0;
}