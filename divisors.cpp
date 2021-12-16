#include <bits/stdc++.h>

using namespace std;

set<int> getDivisors(int n)
{
    if (n == 0)
        throw std::invalid_argument("All natural numbers are divisors of zero");

    set<int> result({1, n});
    int sr = sqrt(n);

    for (int i = 2; i <= sr; i++)
    {
        if (n % i == 0)
        {
            // dodajemy znaleziony dzielnik
            result.insert(i);
            // dodajemy jeko odpowiednik po prawej stronie "sqrt"
            result.insert(n / i);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int a;
    cout << "Podaj liczbe\n a = ";
    cin >> a;

    set<int> div = getDivisors(a);
    cout << "Dzielniki:" << endl;
    for (int x : div)
        cout << x << " ";

    cout << endl;
    return 0;
}
