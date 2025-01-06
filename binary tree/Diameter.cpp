
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int diameter =0;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxDepth(Node *root, int& diameter)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxDepth(root->left, diameter);
    int rh = maxDepth(root->right, diameter);
    diameter = max(diameter, lh+rh);
    return 1 + max(lh, rh);
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int depth = maxDepth(root,diameter);

    cout << "Diameter of the binary tree: " << diameter << endl;

    return 0;
}
