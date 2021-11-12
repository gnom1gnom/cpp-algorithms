#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> braces = {"{}[]()", "{[({})]}"};
    for (string b : braces)
    {
        size_t f1, f2, f3;
        while ((f1 = b.find("{}")) != string::npos || (f2 = b.find("[]")) != string::npos || (f3 = b.find("()")) != string::npos)
        {
            if ((f1 = b.find("{}")) != string::npos)
                b.erase(f1, 2);

            if ((f2 = b.find("[]")) != string::npos)
                b.erase(f2, 2);

            if ((f3 = b.find("()")) != string::npos)
                b.erase(f3, 2);
        }

        cout << b << endl;
    }

    return 0;
}
