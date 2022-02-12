#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_anagram(string s1, string s2)
{
    map<char, int> freq;
    for (char c : s1) {
        freq[c]++;
    }
    for (char c : s2) {
        freq[c]--;
    }
    for (auto& [c, f] : freq) {
        if (f)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 1;; i++) {
        bool ok = true;
        for (int coef = 2; coef <= 6; coef++) {
            if (!is_anagram(to_string(i), to_string(i * coef))) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
