
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

bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if (p->data != q->data)
    {
        return false;
    }

    bool lh = isSameTree(p->left, q->left);
    if (!lh)
    {
        return false;
    }
    bool rh = isSameTree(p->right, q->right);
    if (!rh)
    {
        return false;
    }

    return true;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->right = new Node(4);

    bool b = isSameTree(root1, root2);

    cout << b << endl;

    return 0;
}