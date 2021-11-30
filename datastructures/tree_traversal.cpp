#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/** Drukujemy on najniższego poziomu do korzenia,
 * na każdym przechodzimy od lewej do prawej
 **/
void printPostorder(struct Node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->data << " " << flush;
}

/** Na każdym rozgałęzienu
 * drukujemy lewe pod-drzewo
 * drukujemy rozgałęzienie
 * drukujemy prawe poddrzewo
 **/
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " " << flush;

    /* now recur on right child */
    printInorder(node->right);
}

/**
 * Schodź (rekursywnie) na lewo do dna,
 * a potem rekursywnie na prawo
 * drukuj gałąź od razu, zanim odwiedzisz dzieci
 **/

void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " " << flush;

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

/* Driver program to test above functions*/
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "\nPreorder traversal of binary tree is \n"
         << flush;
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n"
         << flush;
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n"
         << flush;
    printPostorder(root);

    return 0;
}
