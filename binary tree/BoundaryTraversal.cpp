#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* node) {
    return (node->left == nullptr && node->right == nullptr);
}

void addLeftBoundary(Node* root, vector<int>& res) {
    Node* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

void addRightBoundary(Node* root, vector<int>& res) {
    Node* cur = root->right;
    vector<int> tmp;
    while (cur) {
        if (!isLeaf(cur)) tmp.push_back(cur->data);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = tmp.size()-1; i >= 0; i--) {
        res.push_back(tmp[i]);
    }
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;
    
    if (!isLeaf(root))
        res.push_back(root->data);
        
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> boundary = boundaryTraversal(root);
    for (int i : boundary) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}