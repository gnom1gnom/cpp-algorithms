#include <iostream>
#include <vector>

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <bitset>
#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

const int N = 40; // długość łańcucha s

int min(int a, int b)
{
    return (a < b) ? a : b;
}

string slowLongestPalindrome(string mainString)
{
    int n = mainString.size();
    if (n == 0)
        return "";

    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; i++)
    {
        // dla palindromów które w środku mają pojedynczą literę - abcDcba
        d1[i] = 1;
        // 1. dopuki nie przesuneliśmy sie do poczatku stringu &&
        // 2. dopuki nie przesunelismy si do konca stringu &&
        // 3. dopuki sąsiadujące w danej odległosci litery są takie same
        while (0 <= i - d1[i] && i + d1[i] < n && mainString[i - d1[i]] == mainString[i + d1[i]])
        {
            // poszerza sprawdzaną odległośc o 1
            d1[i]++;
        }

        // dla palindromów które NIE mają w środku pojedynczą literę - abccba
        d2[i] = 0;
        while (0 <= i - d2[i] - 1 && i + d2[i] < n && mainString[i - d2[i] - 1] == mainString[i + d2[i]])
        {
            d2[i]++;
        }
    }

    return "";
}

string longestPalindrome(string mainString)
{
    int n = mainString.size();
    if (n == 0)
        return "";
    n = 2 * n + 1; // count the next position
    int LPS[n];    // array to store longest palindrome length
    LPS[0] = 0;    // Initialize starting even position as 0
    LPS[1] = 1;    // Initialize starting odd position as 1
    int centerIndex = 1;
    int rightIndex = 2;
    int right = 0, left;
    int maxPalLength = 0, maxCenterIndex = 0;
    int start = -1, end = -1, diff = -1;

    for (right = 2; right < n; right++)
    {
        left = 2 * centerIndex - right; // calculate left position using center and right
        LPS[right] = 0;
        diff = rightIndex - right;

        if (diff > 0)
            LPS[right] = min(LPS[left], diff);
        while (((right + LPS[right]) < n && (right - LPS[right]) > 0) && (((right + LPS[right] + 1) % 2 == 0) || (mainString[(right + LPS[right] + 1) / 2] == mainString[(right - LPS[right] - 1) / 2])))
        {
            LPS[right]++;
        }

        if (LPS[right] > maxPalLength)
        { // max palindrome length
            maxPalLength = LPS[right];
            maxCenterIndex = right;
        }

        if (right + LPS[right] > rightIndex)
        {
            centerIndex = right;
            rightIndex = right + LPS[right];
        }
    }

    start = (maxCenterIndex - maxPalLength) / 2;
    end = start + maxPalLength - 1;
    string palindrome;

    for (int i = start; i <= end; i++)
        palindrome += mainString[i];
    return palindrome;
}

int main(int argc, char *argv[])
{
    // https://eduinf.waw.pl/inf/alg/001_search/0060.php
    string s, palindrome;
    cout << "Enter String:";
    // cin >> s;
    s = "CDDDABCDCCDCCDDADABDDDBDCAABBBCBADBCABDA";
    // s = "sabacbcabacbx";
    palindrome = longestPalindrome(s);
    cout << "Longest palindrome is: " << palindrome << endl;

    int i, evenOdd, rp, k, R[2][N + 1];
    // palindromy parzyste
    fill(R[0], R[0] + N + 1, 0);

    // palindromy nieparzyste
    fill(R[1], R[1] + N + 1, 0);

    // tutaj będziemy zapamiętywać index największego promienia
    int maxRindex[2];
    maxRindex[0] = 0;
    maxRindex[1] = 0;

    s = "@" + s + "#"; // wstawiamy wartowników

    for (evenOdd = 0; evenOdd <= 1; evenOdd++)
    {
        R[evenOdd][0] = rp = 0;
        i = 1;
        while (i <= N) // dopuki nie doszlismy do konca slowa
        {
            while (s[i - rp - 1] == s[i + evenOdd + rp]) // sprawdzamy i poszerzamy promien palindormu; evenodd zalatwia kwestie nieparzystych
                rp++;
            R[evenOdd][i] = rp;

            // zapamiętujemy maksymalny promień
            if (R[evenOdd][i] > R[evenOdd][maxRindex[evenOdd]])
                maxRindex[evenOdd] = i;

            k = 1;
            while ((R[evenOdd][i - k] != rp - k) && (k < rp)) // przesuwamy sie w lewo od środka palindromu
            {
                R[evenOdd][i + k] = min(R[evenOdd][i - k], rp - k); // wyznaczamy promień lustrzanego palindromu wewnętrznego

                // zapamiętujemy maksymalny promień
                if (R[evenOdd][i + k] > R[evenOdd][maxRindex[evenOdd]])
                    maxRindex[evenOdd] = i + k;

                k++; // przechodzimy do nastepnel powzycji pod parasolem palindormu
            }
            rp = max(rp - k, 0); // wyznaczamy promień początkowy palindromu
            i += k;              // pomijamy wyliczone palindromy lustrzane
        }
    }

    s = s.substr(1, N); // usuwamy wartowników

    // drukujemy największy palindrom parzysty i nieparzysty
    for (evenOdd = 0; evenOdd <= 1; evenOdd++)
    {
        cout << "Longest " << ((i % 2) ? "even" : "odd") << " palindrome: ";
        i = maxRindex[evenOdd];
        rp = R[evenOdd][i];
        cout << s.substr(i - rp - 1, 2 * rp + evenOdd) << endl;
    }

    // prezentujemy wyliczone palindromy
    // for (i = 1; i <= N; i++)
    // {
    //     for (j = 0; j <= 1; j++)
    //         for (rp = R[j][i]; rp > 0; rp--)
    //         {
    //             // zrób wycinek liter spod parasola promienia palindromu
    //             cout << s.substr(i - rp - 1, 2 * rp + j) << endl;
    //         }
    // }
    cout << endl;
    return 0;
}