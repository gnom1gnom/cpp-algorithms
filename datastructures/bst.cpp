#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node
{

public:
    T value;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;

    Node(T value)
    {
        this->value = value;
    }

    void insert(T value)
    {

        /*
        if (value <= this->value)
        {
            if (left)
                left->insert(value);
            else
                left = new Node(value);
        }
        else
        {
            if (right)
                right->insert(value);
            else
                right = new Node(value);
        }
        */

        Node **node;

        if (value <= this->value)
            node = &left;
        else
            node = &right;

        if (*node)
            (*node)->insert(value);
        else
            (*node) = new Node(value);
    }
};

template <class T>
class BTS
{
    Node<T> *root = nullptr;

public:
    BTS(){};

    BTS(int value)
    {
        root = new Node<T>(value);
    }

    void insert(int value)
    {
        if (!root)
            root = new Node<T>(value);
        else
            root->insert(value);
    }

    void search(int value)
    {
        Node<T> *node = root;

        while (node && node->value != value)
        {
            cout << node->value;
            if (value < node->value)
            {
                cout << " L " << flush;
                node = node->left;
            }
            else
            {
                cout << " R " << flush;
                node = node->right;
            }
        }

        if (node)
            cout << node->value << endl;
        else
            cout << "???" << endl;
    }
};

void minimalBST(BTS<int> &bts, vector<int> &arr, int left, int right)
{
    if (right - left >= 0)
    {
        // int middle = left + ceil((right - left) / 2);
        // rezultat taki sam a arymetka prostsza
        int middle = (right + left) / 2;
        bts.insert(arr[middle]);

        minimalBST(bts, arr, left, middle - 1);
        minimalBST(bts, arr, middle + 1, right);
    }
}

BTS<int> minimalBST(vector<int> arr)
{
    BTS<int> bts;
    minimalBST(bts, arr, 0, arr.size() - 1);
    return bts;
}

int main(int argc, char const *argv[])
{

    vector<int> val = {5, 4, 8, 6, 2, 3, 9};
    BTS<int> bts;

    for (int v : val)
        bts.insert(v);

    bts.search(10);
    bts.search(6);

    vector<int> min = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    BTS<int> min_bts = minimalBST(min);

    return 0;
}
