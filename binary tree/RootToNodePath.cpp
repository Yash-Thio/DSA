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

bool findPath(Node *root, vector<int> &path, int target)
{
    if (root == nullptr)
    {
        return false;
    }
    path.push_back(root->data);

    if (root->data == target)
    {
        return true;
    }

    if (findPath(root->left, path, target) || findPath(root->right, path, target))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int val = 5;

    vector<int> path;
    if (findPath(root, path, val))
    {
        cout << "Path from root to " << val << ": ";
        for (int i : path)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "Node not found in tree";
    }
    cout << endl;

    return 0;
}