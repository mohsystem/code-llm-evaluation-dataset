// C++ code
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string roll_hash(const string &s, int length) {
    const long long p = 31, m = (1LL << 61) - 1;
    long long hash_value = 0, p_pow = 1;
    for (int i = 0; i < length; ++i) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

string search_substring(const string &s, int length) {
    unordered_map<long long, vector<int>> hashes;
    const long long p = 31, m = (1LL << 61) - 1;
    long long curr_hash = roll_hash(s, length);
    long long p_pow = 1;
    for (int i = 1; i < length; ++i) p_pow = (p_pow * p) % m;
    hashes[curr_hash].push_back(0);
    
    for (int i = 1; i <= s.size() - length; ++i) {
        curr_hash = (curr_hash - (s[i - 1] - 'a' + 1) * p_pow % m + m) % m;
        curr_hash = (curr_hash * p + (s[i + length - 1] - 'a' + 1)) % m;
        if (hashes.count(curr_hash)) {
            for (int start : hashes[curr_hash]) {
                if (s.substr(start, length) == s.substr(i, length)) {
                    return s.substr(start, length);
                }
            }
        }
        hashes[curr_hash].push_back(i);
    }
    return "";
}

string longestDupSubstring(string s) {
    int left = 1, right = s.size() - 1;
    string result;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string substring = search_substring(s, mid);
        if (!substring.empty()) {
            result = substring;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    cout << longestDupSubstring("banana") << endl;  // Output: "ana"
    cout << longestDupSubstring("abcd") << endl;    // Output: ""
    return 0;
}