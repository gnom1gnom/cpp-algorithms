#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

// https://www.techiedelight.com/split-binary-tree-into-two-trees/

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Update the reference variable `result` to `true` if the size of the binary
// a tree rooted at `root` or the size of any of its subtrees is exactly `n/2`
static pair<int, int> getLengthPair(Node *node)
{
    if (!node->left && !node->right)
        return make_pair(0, 0);

    pair<int, int> result = make_pair(0, 0);
    if (node->left)
    {
        auto left = getLengthPair(node->left);
        result.first = left.first + left.second + 1;
    }

    if (node->right)
    {
        auto right = getLengthPair(node->right);
        result.second = right.first + right.second + 1;
    }

    fmt::print("{} ({},{})\n", node->data, result.first, result.second);

    return result;
}

// Function to check if a given binary tree can be split into
// two binary trees of equal size
bool splitTree(Node *root)
{
    auto result = getLengthPair(root);
    return (result.first > result.second) ? result.first - 1 == result.second : result.second - 1 == result.first;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (splitTree(root))
    {
        cout << "The binary tree can be split" << endl;
    }
    else
    {
        cout << "The binary tree cannot be split" << endl;
    }

    return 0;
}