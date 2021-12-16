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

int main(int argc, char const *argv[])
{
    int n = 23;
    cout << n << ": " << isPrime(n) << endl;
    return 0;
}
