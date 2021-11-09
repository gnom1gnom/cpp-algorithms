#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = ")))()()()())())())))))())))))))())()))()()()))))))";

    size_t pos = s.find("()");
    while (pos != std::string::npos)
    {
        s.erase(pos, 2);
        pos = s.find("()");
    }

    cout << s.length();
    return 0;
}
