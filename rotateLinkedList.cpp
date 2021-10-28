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
    if (!k)
        return head;

    Node *iter{head};
    // go to the end of the list and find it's lenght
    long length;

    int rotations = k;

    for (length = 1; iter->next; length++)
    {
        iter = iter->next;
    }

    // count the modulo rotation number
    rotations = rotations % length;
    if (!rotations)
        return head;

    cout << "List will be rotated " << rotations << " times" << std::endl;
    // make a circuar list
    iter->next = head;

    int endIndex = length - rotations;
    // idiemy do elementu gdzie musimy rozłączyć listę
    for (long i = 1; i < endIndex; i++)
    {
        head = head->next;
    }

    Node *end = head;
    head = head->next;
    end->next = nullptr;

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

    int k = 58;
    cout << "Original linked list, to be rotated " << k << " times" << std::endl;
    printlist(head);
    head = rotate(head, k);
    cout << "Linked list after rotation" << std::endl;
    printlist(head);
}