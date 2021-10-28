#include <bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N];

// recursive function for fibonacci
int fibonacci(int n)
{
    // if n is zero or one return the number
    if (n <= 1)
    {
        return n;
    }
    // recursive call to n-1 and n-2
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci2(int n)
{
    // we will make a call if an element in array dp is -1
    // jeśli dla n-tej pozycji nie policzono jeszcze wartości
    if (dp[n] == -1)
    {
        if (n <= 1)
        {
            dp[n] = n;
        }
        else
        {
            // call to n-1  and n-2
            dp[n] = fibonacci2(n - 1) + fibonacci2(n - 2);
        }
    }
    return dp[n];
}

int fibonacci3(int n)
{
    long left{0}, right{1}, sum{0};
    // cout << left << " " << right << " ";

    for (int i = 1; i < n; i++)
    {
        sum = left + right;
        left = right;
        right = sum;
        // cout << sum << " ";
    }
    // cout << endl;
    return sum;
}

int fibonacci4(int n)
{

    double res = (1 + sqrt(5)) / 2;
    return round(pow(res, n) / sqrt(5));
}

/* Array to store fibonacci numbers.  fib[i] is going
   to store (i+2)'th Fibonacci number*/
int fib[N];

// Stores values in fib and returns index of the largest
// fibonacci number smaller than n.
int largestFiboLessOrEqual(int n)
{
    fib[0] = 1; // Fib[0] stores 2nd Fibonacci No.
    fib[1] = 2; // Fib[1] stores 3rd Fibonacci No.

    // Keep Generating remaining numbers while previously
    // generated number is smaller
    int i;
    for (i = 2; fib[i - 1] <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    // Return index of the largest fibonacci number
    // smaller than or equal to n. Note that the above
    // loop stopped when fib[i-1] became larger.
    return (i - 2);
}

/* Returns pointer to the char string which corresponds to
   code for n */
char *fibonacciEncoding(int n)
{
    // Find the largest Fibonacci number f less than or equal to n
    int i = largestFiboLessOrEqual(n);

    // allocate memory for codeword
    // The length of codeword for n will be i+3 characters
    // One for extra 1 appended at the end, One because i is an index, and one for ‘\0’
    char *codeword = (char *)malloc(sizeof(char) * (i + 3));
    // wypełniamy wszystkie pozycje zerami
    memset(codeword, '0', i + 2);
    //  dodajemy 1 bo taka jest konwencja zapisu, /0 bo terminujemy string
    codeword[i + 1] = '1';
    codeword[i + 2] = '\0';

    // index of the largest Fibonacci f <= n
    // indexs największej liczby fibonaciego, mniejszej niż zadane n

    // dopuki pozostała nam jakaś reszta z odejmowania
    while (n)
    {
        // Mark usage of Fibonacci f (1 bit)
        // oznaczamy aktualny indeks liczby z ciągu fib.
        codeword[i] = '1';

        // odejmujemy od aktualnej reszty z odejmowania tą liczbę fib.
        n = n - fib[i];

        // jeśli nie zostało nam wiecej rzeszty z odejmowania kończymy
        if (!n)
            break;

        // będziemy sprawdzać poprzednią liczbę fib.
        i = i - 1;

        // dopuki nie znalaźliśmy mniejszej liczby fib niż nasza reszta z odejmowania
        // i nie doszliśmy do ostatniej liczby
        while (fib[i] > n)
        {
            // szukamy największej liczby fibonaciego, mniejszej niż reszta z odejmowani
            i = i - 1;
        }
    }

    // return pointer to codeword
    return codeword;
}

int main()
{
    int n;
    n = 20;
    long f = fibonacci(n);
    cout << f << endl;

    // initializing values of an array to -1
    memset(dp, -1, sizeof(dp));
    f = fibonacci2(n);
    cout << f << endl;

    f = fibonacci3(n);
    cout << f << endl;

    f = fibonacci4(n);
    cout << f << endl;

    int num = 8039213;
    cout << "Fibonacci code word for " << num << " is " << fibonacciEncoding(num) << endl;

    return 0;
}