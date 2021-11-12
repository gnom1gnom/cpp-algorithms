#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string baseDir = "/home/ubuntu/projects/c/cpp-algorithms/bin/";
    string baseFilename = "names_list_00.txt";

    ifstream baseFS(baseDir + baseFilename);

    // file counters
    int c{0}, cpp{0}, cs{0};

    string name = baseFilename.substr(0, baseFilename.rfind("."));

    ofstream c_out(baseDir + "c_" + name + ".txt");
    ofstream cpp_out(baseDir + "cpp_" + name + ".txt");
    ofstream cs_out(baseDir + "cs_" + name + ".txt");

    while (baseFS)
    {
        string fileName;
        getline(baseFS, fileName);
        cout << fileName << "\n";

        string ext = fileName.substr(fileName.rfind(".") + 1, fileName.size() - 1);
        cout << ext << "\n";
        if (ext == "c")
        {
            c++;
            c_out << fileName << endl;
        }
        else if (ext == "cpp")
        {
            cpp++;
            cpp_out << fileName << endl;
        }
        else if (ext == "cs")
        {
            cs++;
            cs_out << fileName << endl;
        }
    }

    baseFS.close();
    c_out.close();
    cpp_out.close();
    cs_out.close();

    return 0;
}
