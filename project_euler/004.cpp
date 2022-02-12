#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_palindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    int ans = -1;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (is_palindrome(to_string(i * j))) {
                ans = max(ans, i * j);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
