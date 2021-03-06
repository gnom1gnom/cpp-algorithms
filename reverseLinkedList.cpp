#include <iostream>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

Node *getPrev(Node *&head, Node *node, Node *next)
{
    if (!next)
    {
        head = node;
        return node;
    }

    Node *prev = getPrev(head, node->next, next->next);
    prev->next = node;
    node->next = nullptr;

    return node;
}

// Function to rotate a linked list
void reverse(Node *&head)
{
    getPrev(head, head, head->next);
}

// Function to take Linked list input
void input(Node **head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

// function to print linked list
void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // taking input for linked list
    Node *head = NULL;
    // Creating a linked list 1->2->3->4->5

    input(&head, 5);
    input(&head, 4);
    input(&head, 3);
    input(&head, 2);
    input(&head, 1);

    printlist(head);
    reverse(head);
    cout << "Linked list after reverse" << std::endl;
    printlist(head);
}