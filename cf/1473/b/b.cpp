#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve(int _t)
{
    string s, t; cin >> s >> t;
    int p = gcd(s.size(), t.size());
    string pat = s.substr(0, p);
    for (int i = 0; i < s.size(); i += p) {
        if (s.find(pat, i) != i) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < t.size(); i += p) {
        if (t.find(pat, i) != i) {
            cout << "-1\n";
            return;
        }
    }
    
    for (int i = 0; i < s.size() / p; i++) cout << t;
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

