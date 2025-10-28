#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class BinaryTree
{
    vector<int> tree; // array representation
public:
    BinaryTree(int size) 
    {
        tree.resize(size, -1); // -1 means empty
    }

    void insert(int index, int value) 
    {
        if (index < tree.size())
            tree[index] = value;
        else
            cout << "Index out of bounds!\n";
    }

    void display() 
    {
        cout << "Binary Tree (array representation): ";
        for (int val : tree) 
        {
            if (val == -1) cout << "_ ";
            else cout << val << " ";
        }
        cout << endl;
    }

    // Check if tree is BST (using array index logic)
    bool isBSTUtil(int index, long long minVal, long long maxVal) 
    {
        if (index >= tree.size() || tree[index] == -1)
            return true;

        int val = tree[index];
        if (val <= minVal || val >= maxVal)
            return false;

        // left child = 2*i + 1, right child = 2*i + 2
        return isBSTUtil(2 * index + 1, minVal, val) &&
               isBSTUtil(2 * index + 2, val, maxVal);
    }

    bool isBST() 
    {
        return isBSTUtil(0, LLONG_MIN, LLONG_MAX);
    }
};

int main() 
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    BinaryTree bt(n);
    cout << "Enter elements (-1 for empty position):\n";
    for (int i = 0; i < n; i++) 
    {
        int val;
        cin >> val;
        bt.insert(i, val);
    }

    bt.display();

    if (bt.isBST())
        cout << "The tree is a BST.\n";
    else
        cout << "The tree is NOT a BST.\n";
    return 0;
}