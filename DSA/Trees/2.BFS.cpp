#include<iostream>
#include<vector>
#include<queue>

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

vector<vector<int>> levelorder(Node* head)
{
    vector<vector<int>> ans;
    if(head == NULL)
    return ans;

    queue<Node*> q;
    q.push(head);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for(int i=0 ; i<size ; i++)
        {
            Node* node = q.front();
            q.pop();

            if(node->left != NULL)
            q.push(node->left);
            if(node->right != NULL)
            q.push(node->right);

            level.push_back(node->data);
        }

        ans.push_back(level);
    }
    return ans;
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

    cout<<"Level Order:"<<endl;
    vector<vector<int>> res = levelorder(root);
    for(int i=0 ; i<res.size() ; i++)
    {
        for(int j=0 ; j<res[i].size() ; j++)
        {
            cout<<res[i][j]<<" ";
        }
    }
    cout<<endl;

    return 0;
}