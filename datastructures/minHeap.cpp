#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Data structure to store a max-heap node
struct PriorityQueue
{
private:
	// vector to store heap elements
	// int *A = new int[1000];
	// int s = 0;
	vector<int> A;

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
			if (A[l] < A[m]) // sprawdzamy czy jest miejsze niż rodzic
			{
				m = l;
			}
		}

		if (r < size()) // sprawdzamy lewe dzisko istnieje
		{
			if (A[r] < A[m]) // sprawdzamy czy jest miejsze niż rodzic
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
			int p = parent(i); // pobieramy rodzica
			if (A[p] > A[i])   // to jest min heap, więc rodzic nie moze być wiekszy niż dziecko
			{
				swap(A[p], A[i]);
				heapify_up(p);
			}
		}
	}

public:
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
	void push(int key)
	{
		A.push_back(key);
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
	int top()
	{
		int s = size();
		if (s > 0)
		{
			return A[0];
		}
		else
		{
			return NULL;
		}
	}
};

// Max Heap implementation in C++
int main()
{
	PriorityQueue pq;

	// Note: The element's value decides priority

	for (int n = 10; n >= 0; n--)
		pq.push(n); // generate numbers;

	cout << "Size is " << pq.size() << endl;

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	pq.push(5);
	pq.push(4);
	pq.push(45);

	cout << endl
		 << "Size is " << pq.size() << endl;

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << endl
		 << boolalpha << pq.empty();

	return 0;
}