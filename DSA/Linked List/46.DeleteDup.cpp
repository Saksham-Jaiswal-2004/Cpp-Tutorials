#include<iostream>

using namespace std;

class ListNode
{
    public:
    int val;
    ListNode* next;

    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

ListNode* deleteDuplicates(ListNode* head) 
{
    if(head==NULL)
    return NULL;
    
    ListNode* temp = head;
    
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->val == temp->next->val)
        {
            ListNode* temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

void printList(ListNode* head)
{
    if(head==NULL)
    return;

    ListNode* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    int data[] = {1,1,2,3,3};
    ListNode* root = new ListNode(data[0]);
    ListNode* temp = root;

    int len = sizeof(data)/sizeof(int);

    for(int i=1 ; i<len ; i++)
    {
        ListNode* newNode = new ListNode(data[i]);
        temp->next = newNode;
        temp = newNode;
    }

    printList(root);
    root = deleteDuplicates(root);
    printList(root);

    return 0;
}