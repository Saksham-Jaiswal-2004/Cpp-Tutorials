#include<iostream>
#include<vector>

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

void reorderList(ListNode* head) 
{
    if (!head || !head->next || !head->next->next) 
    return;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    while (curr) 
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow->next = nullptr;

    ListNode* first = head;
    ListNode* second = prev;
    while (second) 
    {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}

void printList(ListNode* head)
{
    if(head == NULL)
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
    vector<int> data = {1,2,3,4,5,6};
    ListNode* root = new ListNode(data[0]);
    ListNode* temp = root;

    for(int i=1 ; i<data.size() ; i++)
    {
        ListNode* newNode = new ListNode(data[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    printList(root);
    reorderList(root);
    printList(root);

    return 0;
}