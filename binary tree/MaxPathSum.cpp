
#include <iostream>
#include <climits>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int maxPathSum(Node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = maxPathSum(root->left, maxi);
    lh = lh + root->data;
    int rh = maxPathSum(root->right, maxi);
    rh = rh + root->data;

    maxi = max(maxi, lh + rh + root->data);

    return max(lh, rh);
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int maxi = INT_MIN;

    int path = maxPathSum(root, maxi);

    cout << "Maximum path of the binary tree: " << path << endl;

    return 0;
}