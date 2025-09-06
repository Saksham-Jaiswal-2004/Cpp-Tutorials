#include<iostream>

using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = this->right = NULL;
    }
};

void inorder(Node* head)
{
    if(head == NULL)
    return;

    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}

void preorder(Node* head)
{
    if(head == NULL)
    return;

    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}

void postorder(Node* head)
{
    if(head == NULL)
    return;

    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout<<"Inorder:"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Preorder:"<<endl;
    preorder(root);
    cout<<endl;
    
    cout<<"Postorder:"<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}