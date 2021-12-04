#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

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

    static int getLength(Node<T> *node)
    {
        if (!node)
            return -1;

        if (!node->left && !node->right)
            return 0;

        return max(getLength(node->left), getLength(node->right)) + 1;
    }

    static pair<int, int> getLengthPair(Node<T> *node)
    {
        if (!node)
            return make_pair(-1, -1);

        if (!node->left && !node->right)
            return make_pair(0, 0);

        pair<int, int> lL = getLengthPair(node->left);
        pair<int, int> rL = getLengthPair(node->right);

        pair<int, int> result = make_pair(max(lL.first, lL.second) + 1, max(rL.first, rL.second) + 1);

        if (abs(result.first - result.second) > 1)
            fmt::print("{} ({},{})\n", node->value, result.first, result.second);

        return result;
    }

    static pair<int, int> getMinMax(Node<T> *node)
    {
        if (!node)
            return make_pair(INT_MAX, INT_MIN);

        if (!node->left && !node->right)
            return make_pair(node->value, node->value);

        pair<int, int> lMM;
        if (node->left)
            lMM = getMinMax(node->left);
        else
            lMM = make_pair(node->value, node->value);

        pair<int, int> rMM;
        if (node->right)
            rMM = getMinMax(node->right);
        else
            rMM = make_pair(node->value, node->value);

        if (node->value < lMM.second)
            fmt::print("{} left: ({},{})\n", node->value, lMM.first, lMM.second);

        if (node->value > rMM.first)
            fmt::print("{} right: ({},{})\n", node->value, rMM.first, rMM.second);

        pair<int, int> result = make_pair(min(lMM.first, rMM.first), max(lMM.second, rMM.second));

        return result;
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

    Node<T> *getRoot()
    {
        return root;
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

    vector<list<Node<T> *>> createLevelLinkedList()
    {
        vector<list<Node<T> *>> result;
        result.push_back({getRoot()});

        list<Node<T> *> nextLevel;
        do
        {
            nextLevel.clear();

            for (Node<T> *n : result[result.size() - 1])
            {
                if (n->left)
                    nextLevel.push_back(n->left);
                if (n->right)
                    nextLevel.push_back(n->right);
            }

            if (nextLevel.size() > 0)
                result.push_back(nextLevel);

        } while (nextLevel.size() > 0);

        return result;
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

    vector<int> val = {5, 4, 8, 6, 2, 3, 9, 12, 15, 16};
    BTS<int> bts;

    for (int v : val)
        bts.insert(v);

    bts.search(10);
    bts.search(6);

    auto h = Node<int>::getLengthPair(bts.getRoot());
    fmt::print("Tree height: ({},{})\n", h.first, h.second);

    auto mm = Node<int>::getMinMax(bts.getRoot());
    fmt::print("Root min max: ({},{})\n", mm.first, mm.second);

    cout << "----------------------\n";

    auto levels1 = bts.createLevelLinkedList();

    for (auto l : levels1)
    {
        for (auto *n : l)
        {
            cout << n->value << " ";
        }
        cout << endl;
    }

    cout << "----------------------\n";
    vector<int> min = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BTS<int> min_bts = minimalBST(min);

    auto levels2 = min_bts.createLevelLinkedList();

    for (auto l : levels2)
    {
        for (auto *n : l)
        {
            cout << n->value << " ";
        }
        cout << endl;
    }

    cout << "----------------------\n";

    BTS<int> bad_bts{20};
    bad_bts.insert(10);
    bad_bts.insert(30);
    bad_bts.getRoot()->left->insert(25);

    auto bad_mm = Node<int>::getMinMax(bad_bts.getRoot());
    fmt::print("Root min max: ({},{})\n", bad_mm.first, bad_mm.second);

    cout << "----------------------\n";

    return 0;
}
