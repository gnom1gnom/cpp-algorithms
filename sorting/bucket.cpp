#define FMT_HEADER_ONLY

#include <bits/stdc++.h>
#include <fmt/core.h>

using namespace std;

template <typename T>
class BucketSorter
{
private:
    virtual int getBucket(T value, T max) = 0;

public:
    vector<T> L; // list ot be sorted
    int k;       // bucket count

    BucketSorter(vector<T> L, int k)
    {
        this->L = L;
        this->k = k;
    }

    void print()
    {
        for (int i = 0; i < L.size(); i++)
            fmt::print("{} ", L[i]);

        fmt::print("\n");
    }

    void print(string message)
    {
        fmt::print("{}\n", message);
        print();
    }

    /**
     * Sortuje liczby dodatnie i ujemne
     **/
    void bucketSort()
    {
        vector<vector<T>> buckets(k);

        T min = L[0], max = L[0];
        for (int i = 0; i < L.size(); i++)
        {
            if (L[i] > max)
                max = L[i];
            else if (L[i] < min)
                min = L[i];
        }

        max = (max + min > 0) ? max : -min;
        max++;

        for (auto val : L)
            buckets[getBucket(val, max)].push_back(val);

        for (auto &vals : buckets)
            sort(vals.begin(), vals.end());

        int i = 0;
        for (auto vals : buckets)
            for (auto val : vals)
                L[i++] = val;
    }
};

template <typename T>
class FractionBucketSorter : public BucketSorter<T>
{
    using BucketSorter<T>::BucketSorter;
    int getBucket(T value, T max)
    {
        return value * this->k;
    }
};

template <typename T>
class PositiveBucketSorter : public BucketSorter<T>
{
    using BucketSorter<T>::BucketSorter;
    int getBucket(T value, T max)
    {
        return (double(value) / double(max) * this->k);
    }
};

template <typename T>
class NegativeBucketSorter : public BucketSorter<T>
{
    using BucketSorter<T>::BucketSorter;
    int getBucket(T value, T max)
    {
        return ((double(value) / double(max) + 1) / 2) * this->k;
    }
};

int main()
{
    int k = 5;

    vector<float> A = {0.8, 0.6, 0.1, 0.9, 0.07, 0.04, 0.0, 0.09, 0.8, 0.68};

    FractionBucketSorter<float> fbs(A, k);
    fbs.print();
    fbs.bucketSort();
    fbs.print("Po posortowaniu:");

    fmt::print("\n-----------------------------------------\n");
    vector<int> B = {0, 8, 4, 12, -2, 10, 6, 14, -1, -9, 5, -13, 3, 11, 7, 15};
    NegativeBucketSorter<int> nbs(B, k);
    nbs.print();
    nbs.bucketSort();
    nbs.print("Po posortowaniu:");

    fmt::print("\n-----------------------------------------\n");
    vector<float> C = {9.8, 0.6, 10.1, 1.9, 3.07, 3.04, 5.0, 8.0, 4.8, 7.68};
    PositiveBucketSorter<float> pbs(C, k);
    pbs.print();
    pbs.bucketSort();
    pbs.print("Po posortowaniu:");

    return 0;
}