#include <bits/stdc++.h>

using namespace std;

int isPrime(long n)
{
    int pierw, pom;
    pierw = sqrt(n);

    int k = 2; //ustawiamy k na pierwszą liczbę pierwszą

    while (k <= pierw)
    {
        if (n != k && n % k == 0) //dopóki liczba jest podzielna przez k i nie jest podzielnikiem
            return k;

        k++;
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    int n = 37961921;
    cout << n << ": " << isPrime(n) << endl;
    return 0;
}
