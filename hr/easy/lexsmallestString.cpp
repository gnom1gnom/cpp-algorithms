#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> substrings = {"c", "cc", "cca", "cccb"};

    /*
    sort(substrings.begin(), substrings.end(), [](string a, string b)
         {
             for (size_t i = 1; i < a.length() && i < b.length(); i++)
             {
                 if (a[a.length() - i] < b[b.length() - i])
                     return true;
                 if (a[a.length() - i] > b[b.length() - i])
                     return false;
             }

             if (a.length() > b.length())
             {
                 return true;
             }

             return false;
         });
    */
    sort(substrings.begin(), substrings.end(), [](string a, string b)
         {
             cout << a << "+" << b << "?" << b << "+" << a << ":" << (a + b < b + a) << endl;
             return (a + b < b + a);
         });

    string out = "";
    for (string s : substrings)
    {
        out.append(s);
    }

    cout << out << endl
         << "ccacccbccc" << endl;
}