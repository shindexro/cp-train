#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, k; cin >> n >> k;
    char s[n+1];
    int i = 0;
    while (i < n) {
        for (char c = 'a'; i < n && c < 'a' + k; c++) {
            s[i++] = c;
            for (char c2 = c+1; i < n && c2 < 'a' + k; c2++) {
                s[i++] = c;
                if (i == n) break;
                s[i++] = c2;
            }
        }
    }
    s[n] = '\0';
    cout << s << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

