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

    void add(string name)
    {
        Leaf *temp = this;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = new Leaf(name);
    }

    void destroy()
    {
        Leaf *temp = this;
        _destroy(temp);
    }

    void _destroy(Leaf *&leaf)
    {
        while (leaf)
        {
            Leaf *temp = leaf;
            leaf = leaf->next;
            cout << temp->name << " burning\n";
            delete (temp);
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
            tree->add(name);
    }

    cout << "Printing the tree \n";
    Leaf *temp = tree;
    while (temp)
    {
        cout << temp->name << "\n";
        temp = temp->next;
    }

    cout << "Buring down the tree \n";
    tree->destroy();

    return 0;
}
