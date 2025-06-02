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

bool isPalindrome(Node *head)
{
    if(head == NULL)
    return true;

    Node* start = head;
    Node* end = head;
    int len = 0;

    while(end->next != NULL)
    {
        end = end->next;
        len++;
    }

    if(start->data != end->data)
    return false;
    
    start = start->next;
    
    while(len!=0)
    {
        end = head;
        for(int i=0 ; i<len-1 ; i++)
        {
            end  = end->next;
        }
        
        if(start->data != end->data)
        return false;

        len--;
        start = start->next;
    }

    return true;
}

bool isPalindrome2(Node* head)
{
    if(head == NULL)
    return true;

    vector<int> arr;
    Node* temp = head;

    while(temp!=NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int len = arr.size();
    for(int i=0 ; i<len ; i++)
    {
        if(arr[i] != arr[len-i-1])
        return false;
    }

    return true;
}

void printList(Node* root)
{
    if(root == NULL)
    return;

    Node* temp = root;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    vector<int> data = {1,2,1,1,2,1};
    Node* root = new Node(data[0]);
    Node* temp = root;

    for(int i=1 ; i<data.size() ; i++)
    {
        Node* newNode = new Node(data[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    printList(root);
    if(isPalindrome(root))
    cout<<"Palindrome!"<<endl;
    else
    cout<<"Not Palindrome!"<<endl;
    if(isPalindrome2(root))
    cout<<"Palindrome!"<<endl;
    else
    cout<<"Not Palindrome!"<<endl;

    return 0;
}