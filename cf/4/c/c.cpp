#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    unordered_set<string> names;
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (names.find(s) == names.end()) {
            names.insert(s);
            cout << "OK\n";
        } else {
            int lo = 1, hi = (int)1e5;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (names.find(s + to_string(mid)) == names.end())
                    hi = mid;
                else
                    lo = mid + 1;
            }
            names.insert(s + to_string(lo));
            cout << s << lo << "\n";
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

