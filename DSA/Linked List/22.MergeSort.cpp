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

Node* mergeSort(Node* head) 
{
    // Base Case
    if(head==NULL || head->next==NULL)
    return head;

    // Getting middle node
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow;

    // Breaking into left and right parts
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // Recursively Sorting both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merging Both parts
    Node* res = new Node(-1);
    Node* temp = res;

    if(left==NULL)
    temp->next = right;
    if(right==NULL)
    temp->next = left;

    while(left!=NULL && right!=NULL)
    {
        if(left->data > right->data)
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
        else
        {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
    }

    if(left!=NULL)
    temp->next = left;
    if(right!=NULL)
    temp->next = right;

    return res->next;
}

void printList(Node* head)
{
    if(head==NULL)
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
    vector<int> data = {1,4,5,2};

    int len = data.size();
    Node* root = new Node(data[0]);
    Node* temp = root;

    for(int i=1 ; i<len ; i++)
    {
        Node* newNode = new Node(data[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    printList(root);
    root = mergeSort(root);
    printList(root);

    return 0;
}