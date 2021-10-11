#include <cstdio>
#include <iostream>

using namespace std;

struct Leaf
{
    string name;
    Leaf *next;

    Leaf(string name)
    {
        this->name = name;
        this->next = nullptr;
    }

    void add(Leaf *&head, string name)
    {
        Leaf *newLeaf = new Leaf(name);
        if (head == nullptr)
        {
            head = newLeaf;
        }
        else
        {
            Leaf *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newLeaf;
        }
    }

    void destroy(Leaf *&leaf)
    {
        if (leaf == nullptr)
        {
            return;
        }
        else
        {
            while (leaf)
            {
                Leaf* temp = leaf;
                leaf = leaf-> next;
                cout << temp->name << " burning\n";
                delete (temp);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    string names[] = {"dupa", "kupa", "pupa", "glutek"};
    Leaf *tree = nullptr;

    for (string name : names)
    {
        cout << "Adding " << name << " to the tree\n";
        if (tree == nullptr)
            tree = new Leaf(name);
        else
            tree->add(tree, name);
    }

    cout << "Printing the tree \n";
    Leaf *temp = tree;
    while (temp)
    {
        cout << temp->name << "\n";
        temp = temp->next;
    }

    cout << "Buring down the tree \n";
    tree->destroy(tree);

    return 0;
}
