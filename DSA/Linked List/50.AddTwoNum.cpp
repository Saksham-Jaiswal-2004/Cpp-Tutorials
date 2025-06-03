#include<iostream>
#include<vector>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node* addTwoLists(Node* num1, Node* num2) 
{
    if(num1 == NULL && num2 == NULL)
    return NULL;
    if(num1 == NULL)    
    return num2;
    if(num2 == NULL)    
    return num1;

    int len1=0, len2=0;
    Node* temp1 = num1;
    Node* temp2 = num2;

    while(temp1 != NULL)
    {
        temp1 = temp1->next;
        len1++;
    }
    while(temp2 != NULL)
    {
        temp2 = temp2->next;
        len2++;
    }
}

void printList(Node* head)
{
    if(head == NULL)
    return;

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
    vector<int> num1 = {4,5};
    vector<int> num2 = {3,4,5};

    Node* root1 = new Node(num1[0]);
    Node* root2 = new Node(num2[0]);

    Node* temp1 = root1;
    Node* temp2 = root2;

    for(int i=1 ; i<num1.size() ; i++)
    {
        Node* newNode = new Node(num1[i]);
        temp1->next = newNode;
        temp1 = temp1->next;
    }
    for(int i=1 ; i<num2.size() ; i++)
    {
        Node* newNode = new Node(num2[i]);
        temp2->next = newNode;
        temp2 = temp2->next;
    }

    printList(root1);
    printList(root2);

    return 0;
}