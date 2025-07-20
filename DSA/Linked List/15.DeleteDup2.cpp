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

ListNode* deleteDuplicates(ListNode* head) 
{
    if(head == NULL)
    return NULL;

    ListNode* prev = NULL;
    ListNode* key = head;
    ListNode* temp = head;

    while(temp!=NULL && temp->next!=NULL)
    {
        if(key->val == temp->next->val)
        {
            while(key->val == temp->next->val)
            {
               if(temp->next->next == NULL)
               {
                    if(prev == NULL)
                    head = NULL;
                    else
                    prev->next = NULL;

                    return head;
               }

               temp = temp->next;
            }
    
            if(prev!=NULL)
            prev->next = temp->next;
            else
            head = temp->next;
    
            temp = temp->next;
            key = temp;
        }
        else
        {
            if(prev == NULL)
            prev = temp;
            else
            prev = prev->next;

            temp = temp->next;
            key = temp;
        }
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
    vector<int> data = {1,2,3,3,3};
    ListNode* root = new ListNode(data[0]);
    int len = data.size();
    ListNode* temp = root;

    for(int i=1 ; i<len ; i++)
    {
        ListNode* newNode = new ListNode(data[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    printList(root);
    root = deleteDuplicates(root);
    printList(root);

    return 0;
}