#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void postOrderTraversal(Node *root, vector<int> &v, bool b)
{
    if (root == nullptr)
    {
        return;
    }

    postOrderTraversal(root->left, v, true);

    postOrderTraversal(root->right, v, true);

    cout << root->data << " ";
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Post-order traversal: ";
    vector<int> v;
    postOrderTraversal(root, v, true);
    cout << endl;

    return 0;
}