
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findFloor(TreeNode *root, int key)
{
    int floor = -1;

    while (root)
    {
        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }

        if (key > root->val)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}

int main()
{
    // Creating a BST
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    int target = 8;
    int floor = findFloor(root, target);

    if (floor != -1)
    {
        cout << "floor of " << target << " is: " << floor << endl;
    }
    else
    {
        cout << "No floor found!";
    }

    return 0;
}
