#include <cstdio>
#include <iostream>

using namespace std;

struct DoubleListNode
{
    int value;
    DoubleListNode *pre, *next;

    DoubleListNode(int value)
    {
        this->value = value;
    }

    DoubleListNode(DoubleListNode *&pre, int value)
    {
        this->value = value;
        this->pre = pre;
    }

    ~DoubleListNode()
    {
        cout << value << " is dead\n";
    }
};

DoubleListNode *insert(DoubleListNode *&after, int value)
{
    after->next = new DoubleListNode(after, value);
    return after->next;
}

void remove(DoubleListNode *&node)
{
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete (node);
}

void deleteList(DoubleListNode *&head)
{

    while (head->next)
    {

        // if (temp->next)
        // {
        //     // następny element nie będzie miał już poprzednika
        //     temp->next->pre = nullptr;
        //     head = head->next;
        // }
        DoubleListNode *temp = head;
        if (head->next)
        {
            head = head->next;
            head->pre = nullptr;
        }

        delete (temp);
    }

    delete (head);
    head = nullptr;
}

void print(DoubleListNode *head)
{
    for (DoubleListNode *node = head; node; node = node->next)
    {
        cout << node->value << " \n";
    }
}

int main(int argc, char const *argv[])
{
    DoubleListNode *head = new DoubleListNode(0);
    DoubleListNode *tail = head;
    for (size_t i = 1; i < 10; i++)
    {
        tail = insert(tail, i);
    }

    print(head);

    deleteList(head);

    print(head);

    // DoubleListNode *current = head;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     if (i % 2) {

    //     }
    //         remove(current);
    // }

    return 0;
}
