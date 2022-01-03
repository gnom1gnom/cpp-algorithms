#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n % 2 == 0)      // jeżeli n jest parzyste to nie może być liczbą pierwszą
        return (n == 2); // czyba że n to 2 - jedyna liczba parzyszta i pierwsza jednocześnie

    /**
     * Przykładowo dla 12 dzielnikami są {1, 2, 3, 4, 6, 12} i prawdą jest to, że 1·12 = 2·6 = 3·4 = 12.
     * Oznacza to, że nie trzeba wyszukiwać, aż do połowy liczby. Granicę przesuwamy na pierwiastek kwadratowy liczby a.
     * Teraz jeśli będziemy szukać dzielników w zakresie [1, sqrt(a)] to znajdziemy wszystkie w zakresie [sqrt(a), a].
     **/
    int pierw = sqrt(n);

    // szukamy rozpoczynając od 3, i przeskakujemy przez wielokrotności 2 (bo wiemy że n nie jest parzyste)
    for (int i = 3; i <= pierw; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

/**
 * data - tablica z cyframi do permutowania
 * l - określa ile już wykonano zamian
 * r - ile zamian powinno zostać wykonanych.
 */
bool permute(vector<int> digits, int l, int r)
{
    if (l == r) // jeśli została uzyskana nowa permutacja to
    {
        int l = 0;
        for (; r >= 0; r--) // zamień tablicę cyfr na liczbę
        {
            l *= 10;
            l += digits[r];
        }
        return isPrime(l);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(digits[l], digits[i]);
            if (!permute(digits, l + 1, r))
                return false;
            swap(digits[l], digits[i]);
        }
    }
    return true;
}

/**
 * Funkcja isPermutablePrime() przyjmuje jeden argument a, który określa liczbę do sprawdzenia,
 *  a wynikiem działania funkcji jest wartość logiczna sprawdzanego warunku.
 */
bool isPermutablePrime(int a)
{
    if (!isPrime(a))
        return false;

    // owe permutacje będzie łatwiej tworzyć jeśli liczba będzie zapisana jako lista cyfr, dlatego: alokacja pamięci pod cyfry i
    // zapisanie na liście kolejnych cyfr (w kolejności odwrotnej).
    vector<int> digits;
    do
    {
        digits.push_back(a % 10);
    } while ((a /= 10) > 0);

    // Następnie pobierany jest wynik sprawdzania wszystkich permutacji,
    bool b = permute(digits, 0, digits.size() - 1);
    return b;
}

int main(int argc, char const *argv[])
{
    unordered_set<int> primes;

    for (int i = 2; i < 1000; i++)
    {
        if (isPermutablePrime(i))
        {
            cout << i << " ";
        }
    }
    return 0;
}