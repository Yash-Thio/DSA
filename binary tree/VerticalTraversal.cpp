#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> findVertical(Node *root)
{
    map<int, map<int, priority_queue<int>>> mp; // {vertical : {level:[]}}
    queue<pair<Node *, pair<int, int>>> q;      //{node,{vertical,level,}}
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *temp = p.first;
        mp[p.second.first][p.second.second].push(temp->data);
        if (temp->left)
        {
            q.push({temp->left, {p.second.first - 1, p.second.second + 1}});
        }
        if (temp->right)
        {
            q.push({temp->right, {p.second.first + 1, p.second.second + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto v : mp)
    {
        vector<int> col;
        for (auto l : v.second)
        {
            while (!l.second.empty())
            {
                col.push_back(l.second.top());
                cout << l.second.top() << endl;
                l.second.pop();
            }
        }
    }
    return ans;
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<vector<int>> verticalTraversal = findVertical(root);

    cout << "Vertical Traversal: ";

    for (const auto &column : verticalTraversal)
    {
        for (int val : column)
        {
            cout << val << " ";
        }
    }
    cout << endl;

    return 0;
}