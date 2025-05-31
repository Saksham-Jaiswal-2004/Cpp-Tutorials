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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode* result;
    ListNode* head;
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    if(temp1==NULL && temp2==NULL)
    return NULL;

    if(temp1 == NULL)
    {
        result = temp2;
        temp2 = temp2->next;
    }
    else if(temp2 == NULL)
    {
        result = temp1;
        temp1 = temp1->next;
    }
    else if(temp1->val < temp2->val)
    {
        result = temp1;
        temp1 = temp1->next;
    }
    else
    {
        result = temp2;
        temp2 = temp2->next;
    }

    head = result;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->val<temp2->val)
        {
            result->next = temp1;
            result = result->next;
            temp1 = temp1->next;
        }
        else
        {
            result->next = temp2;
            result = result->next;
            temp2 = temp2->next;
        }
    }

    while(temp1!=NULL)
    {
        result->next = temp1;
        result = result->next;
        temp1 = temp1->next;
    }
    
    while(temp2!=NULL)
    {
        result->next = temp2;
        result = result->next;
        temp2 = temp2->next;
    }

    return head;
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
    vector<int> data1 = {3,6,8,9};
    vector<int> data2 = {};
    ListNode* root1 = NULL;
    ListNode* root2 = NULL;

    int len1 = data1.size();
    int len2 = data2.size();

    if(len1!=0)
    root1 = new ListNode(data1[0]);
    if(len2!=0)
    root2 = new ListNode(data2[0]);
    
    ListNode* ans;

    ListNode* temp1 = root1;
    ListNode* temp2 = root2;

    for(int i=1 ; i<len1 ; i++)
    {
        ListNode* newNode = new ListNode(data1[i]);
        temp1->next = newNode;
        temp1 = temp1->next;
    }
    for(int i=1 ; i<len2 ; i++)
    {
        ListNode* newNode = new ListNode(data2[i]);
        temp2->next = newNode;
        temp2 = temp2->next;
    }

    printList(root1);
    printList(root2);

    ans = mergeTwoLists(root1, root2);

    printList(ans);

    return 0;
}