#include <bits/stdc++.h>

using namespace std;

bool isPrime(long n)
{
    int pierw = sqrt(n);

    // zakres poszukiwania dzielników liczby można ograniczyć z góry przez , ponieważ jest to ostatnia liczba, która może być dzielnikiem liczby a.
    for (int i = 2; i <= pierw; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool czyPierwsza(int n)
{
    if (n % 2 == 0)      // jeżeli n jest parzyste to nie może być liczbą pierwszą
        return (n == 2); // czyba że n to 2 - jedyna liczba parzyszta i pierwsza jednocześnie

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

int main(int argc, char const *argv[])
{
    int n = 23;
    cout << n << ": " << czyPierwsza(n) << endl;
    return 0;
}
