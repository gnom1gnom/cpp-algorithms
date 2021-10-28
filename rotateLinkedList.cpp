#include <iostream>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

// Function to rotate a linked list
Node *rotate(Node *head, int k)
{

    // Base condition.
    if (head == NULL)
    {
        return head;
    }

    int len = 1;
    Node *temp = head;

    // Calculate length of the linked list.
    while (temp->next != NULL)
    {
        temp = temp->next;
        len += 1;
    }

    k = k % len;

    // Number of rotations are same as len so no change in LL.
    if (k == len || k == 0)
    {
        return head;
    }

    // To make a circular linked list.
    temp->next = head;

    temp = head;

    for (int i = 0; i < abs(len - k - 1); i++)
    {
        temp = temp->next;
    }

    // Changing pointers.
    head = temp->next;
    temp->next = NULL;

    return head;
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

    int k = 2;
    cout << "Original linked list \n";
    printlist(head);
    head = rotate(head, k);
    cout << "Linked list after rotation \n";
    printlist(head);
}