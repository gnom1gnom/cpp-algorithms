#include <cstdio>
#include <iostream>
#include <stdexcept>

using namespace std;

struct Elem
{
    string value;
    Elem *next;

    Elem(Elem *next, string value) : next{next}, value{value}
    {
    }

    ~Elem()
    {
        cout << value << " deleted" << std::endl;
    }

    static Elem *add(Elem *&top, string value)
    {
        Elem *newElem = new Elem(top, value);
        return newElem;
    }

    static void destroy(Elem *&elem)
    {
        delete (elem);
    }
};

struct Heap
{
    ~Heap()
    {
        while (top)
        {
            pop();
        }
    }

    Elem *top = nullptr;

    Elem *push(string value)
    {
        top = Elem::add(top, value);
        return top;
    }

    string pop()
    {
        if (top)
        {
            string name = top->value;
            Elem *deleteMe = top;
            top = top->next;
            Elem::destroy(deleteMe);
            return name;
        }
        else
            throw std::underflow_error("Heap is empty");
    }
};

main(int argc, char const *argv[])
{
    string names[] = {"dupa", "kupa", "pupa", "glutek"};
    Heap heap;

    for (string name : names)
    {
        cout << "Added " << heap.push(name)->value << std::endl;
    }

    cout << heap.pop() << " poped" << std::endl;

    cout << heap.pop() << " poped" << std::endl;

    return 0;
}
