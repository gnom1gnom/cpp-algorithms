#include <bits/stdc++.h>

using namespace std;

vector<string> processLogs(vector<string> logs, int maxSpan)
{
    unordered_map<int, int> logins;
    unordered_map<int, int> logouts;
    set<int> uids;

    string regexPattern = "\\s+";
    const regex pattern(regexPattern);
    for (string log : logs)
    {
        sregex_token_iterator it{log.begin(), log.end(), pattern, -1};
        vector<string> tokenized{it, {}};

        int uid = stoi(tokenized[0]);
        int ts = stoi(tokenized[1]);
        string type = tokenized[2];

        if (type == "sign-in")
        {
            logins.insert(make_pair(uid, ts));
        }
        else // logout
        {
            logouts.insert(make_pair(uid, ts));
        }
    }

    for (auto login : logins)
    {
        auto logout = logouts.find(login.first);
        if (logout != logouts.end())
        {
            int delta = logout->second - login.second;
            if (delta <= maxSpan)
                uids.insert(login.first);

            cout << login.first << " " << delta << endl;
        }
    }

    cout << endl;
    vector<string> out;
    for (int uid : uids)
    {
        cout << uid << endl;
        out.push_back(to_string(uid));
    }

    return out;
}

int main(int argc, char const *argv[])
{

    vector<string> logs = {"30 99 sign-in", "30 105 sign-out", "12 100 sign-in", "20 80 sign-in", "12 120 sign-out", "20 101 sign-out", "21 110 sign-in"};
    processLogs(logs, 20);

    return 0;
}
