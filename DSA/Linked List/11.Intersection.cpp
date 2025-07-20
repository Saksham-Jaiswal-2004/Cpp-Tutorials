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

// Brute Force Approach
Node* getIntersectionNode(Node* A, Node* B)
{
    Node* temp1 = A;
    Node* temp2 = B;

    if(!A || !B)
    return NULL;
    
    while(temp1 != NULL)
    {
        temp2 = B;
        while(temp2 != NULL)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return NULL;
}

// Optimal Approach
Node* getIntersectionNode2(Node* A, Node* B)
{
    Node* temp1 = A;
    Node* temp2 = B;

    if(!A || !B)
    return NULL;

    while(temp1 != temp2)
    {
        temp1 = temp1? temp1->next : B;
        temp2 = temp2? temp2->next : A;
    }

    return temp1;
}

int main()
{
    int data1[] = {6,2,4,7};
    int data2[] = {5,9};
    Node* A = new Node(3);
    Node* B = new Node(2);
    
    Node* temp = A;
    for(int i: data1)
    {
        Node* newNode = new Node(i);
        temp->next = newNode;
        temp = newNode;
    }

    temp = B;
    for(int i: data2)
    {
        Node* newNode = new Node(i);
        temp->next = newNode;
        temp = newNode;
    }

    Node* point = A;
    for(int i=0 ; i<1 ; i++)
    {
        point = point->next;
    }

    temp->next = point;

    printList(A);
    printList(B);

    Node* res = getIntersectionNode(A,B);
    cout<<"Both Linked Lists are intersected at: "<<res->data<<endl;
    res = getIntersectionNode2(A,B);
    cout<<"Both Linked Lists are intersected at: "<<res->data<<endl;

    return 0;
}