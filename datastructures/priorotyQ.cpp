#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

// Data structure to store a max-heap node
template <class T>
class PriorityQueue
{
private:
    // vector to store heap elements
    // int *A = new int[1000];
    // int s = 0;
    vector<T> A;
    function<bool(T, T)> compare;

    // return parent of `A[i]`
    // don't call this function if `i` is already a root node
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // return left child of `A[i]`
    int left(int i)
    {
        return 2 * i + 1;
    }

    // return right child of `A[i]`
    int right(int i)
    {
        return 2 * i + 2;
    }

    // Recursive heapify-down algorithm.
    // The node at index `i` and its two direct children
    // violates the heap property
    void heapify_down(int p)
    {
        int l = left(p);
        int r = right(p);

        int m = p; // indeks najmniejszego  dziecka, mniejszego niż rodzic

        if (l < size()) // sprawdzamy lewe dzisko istnieje
        {
            if (compare(A[l], A[m])) // sprawdzamy czy jest miejsze niż rodzic
            {
                m = l;
            }
        }

        if (r < size()) // sprawdzamy lewe dzisko istnieje
        {
            if (compare(A[r], A[m])) // sprawdzamy czy jest miejsze niż rodzic
            {
                m = r;
            }
        }

        if (m != p) // jeśli znaleźliśmy mniejsze dziecko
        {
            swap(A[m], A[p]);
            heapify_down(m);
        }
    }

    // Recursive heapify-up algorithm
    void heapify_up(int i)
    {
        if (i) // jeśli to nie pierwszy element w kopcu
        {
            int p = parent(i);       // pobieramy rodzica
            if (compare(A[i], A[p])) // to jest min heap, więc rodzic nie moze być wiekszy niż dziecko
            {
                swap(A[p], A[i]);
                heapify_up(p);
            }
        }
    }

public:
    PriorityQueue(function<bool(int, int)> compare)
    {
        this->compare = compare;
    }

    // return size of the heap
    unsigned int size()
    {
        // return s;
        return A.size();
    }

    // Function to check if the heap is empty or not
    bool empty()
    {
        return size() == 0;
    }

    // insert key into the heap
    void push(T value)
    {
        A.push_back(value);
        heapify_up(size() - 1);
    }

    // Function to remove an element with the highest priority (present at the root)
    void pop()
    {
        int s = size();
        if (s > 0)
        {
            A[0] = A[s - 1];
            heapify_down(0);
        }
    }

    // Function to return an element with the highest priority (present at the root)
    T top()
    {
        int s = size();
        if (s > 0)
            return A[0];
        else
            return NULL;
    }
};

int main(int argc, char const *argv[])
{
    std::random_device rd;                          // obtain a random number from hardware
    std::mt19937 gen(rd());                         // seed the generator
    std::uniform_int_distribution<> distr(1, 9999); // define the range

    PriorityQueue<int> pq([](int x, int y) -> bool
                          { return x < y; });

    for (int n = 0; n < 100; ++n)
        pq.push(distr(gen)); // generate numbers

    fmt::print("top: {}\n", pq.top());
    fmt::print("isempty: {}\n", pq.empty());

    pq.pop();

    fmt::print("top: {}\n", pq.top());
    fmt::print("isempty: {}\n", pq.empty());
    return 0;
}
