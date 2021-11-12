#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> dzielniki;
    int n, pierw;

    cout << "Podaj liczbę: ";
    cin >> n;

    pierw = sqrt(n);

    cout << "Czynniki pierwsze liczby " << n << ": ";

    for (int i = 1; i <= pierw; i++)
    {
        if (n % i == 0)
        {
            dzielniki.insert(i);
            if (n / i != i)
                dzielniki.insert(n / i);
        }
    }
    for (int d : dzielniki)
        cout << d << " ";
    cout << endl;

    int ind;
    cout << "Podaj numer dzielnika: ";
    cin >> ind;

    if (dzielniki.size() < ind)
        return 0;

    set<int>::iterator it = dzielniki.begin();

    advance(it, ind - 1);

    cout << "dzielniki[" << ind << "]:" << *it << endl;

    return 0;
}
