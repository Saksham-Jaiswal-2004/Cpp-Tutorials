#include <iostream>

using namespace std;

class Node // Class
{
public:
    int data;
    Node *next;

    Node(int data) // Constructor
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *rotateRight(Node *head, int k)
{
    for (int i = 0; i < k; i++)
    {
        Node *previous = head;
        Node *current;
        Node *forward = head;

        if(previous!=NULL)
        current = previous->next;

        if(head==NULL || head->next==NULL)
        return head;

        while (previous->next->next != NULL)
        {
            previous = previous->next;
            current = previous->next;
        }

        current->next = forward;
        head = current;
        previous->next = NULL;
    }

    return head;
}

int main()
{
    int data[] = {6, 2, 4, 7, 9, 8, 1, 5};
    Node *head = new Node(3);
    Node *temp = head;
    int k = 3;

    for (int i : data)
    {
        Node *newNode = new Node(i);
        temp->next = newNode;
        temp = newNode;
    }

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = rotateRight(head, k);

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}