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

Node* deleteMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    Node* prev = head;

    if(head->next == NULL)
    return NULL;

    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            if(slow!=head)
            prev = prev->next;

            fast = fast->next;
            slow = slow->next;
        }
    }

    prev->next = slow->next;
    free(slow);

    return head;
}

int main()
{
    int data[] = {1,2,3,4,2,1};
    int data2[] = {1,2,3,4,5,2,1};
    Node* head = new Node(data2[0]);
    Node* temp = head;

    for(int i=0 ; i<6 ; i++)
    {
        Node* newNode = new Node(data2[i+1]);
        temp->next = newNode;
        temp = newNode;
    }

    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;

    temp = deleteMiddle(head);
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;

    return 0;
}