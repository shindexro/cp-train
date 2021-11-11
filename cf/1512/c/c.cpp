#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int a, b; cin >> a >> b;
    string s; cin >> s;

    int left = 0, right = s.size() - 1;
    for (; left <= right; left++, right--) {
        if (s[left] == '?' && s[right] == '?') {
            continue;
        } else if (s[right] == '?') {
            s[right] = s[left];
        } else if (s[left] == '?') {
            s[left] = s[right];
        } else if (s[left] != s[right]) {
            cout << "-1\n";
            return;
        }
        if (s[left] == '0') a -= (left == right) ? 1 : 2;
        else b -= (left == right) ? 1 : 2;
    }

    for (left = 0, right = s.size() - 1; left <= right; left++, right--) {
        if (s[left] != '?') continue;
        int elems = (left == right) ? 1 : 2;
        if (a >= elems) {
            s[left] = s[right] = '0';
            a -= elems;
        } else {
            s[left] = s[right] = '1';
            b -= elems;
        }
    }

    if (a == 0 && b == 0) cout << s << "\n";
    else cout << "-1\n";
    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

