#include <bits/stdc++.h>
using namespace std;

bool checkPangram(string str) {
    vector<bool> mark(26, false);
    for (int i = 0; i < str.length(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z')
            mark[str[i] - 'A'] = true;
        if ('a' <= str[i] && str[i] <= 'z')
            mark[str[i] - 'a'] = true;
    }
    for (int i = 0; i <= 25; i++)
        if (mark[i] == false)
            return (false);
    return (true);
}