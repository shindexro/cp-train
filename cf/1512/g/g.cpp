#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

const int C = 1e7+5;
vector<ll> sieve(C, 1);
vector<ll> rd(C, -1);

void prep()
{
    for (int i = 2; i < C; i++) {
        for (int j = i; j < C; j += i) {
            sieve[j] += i;
        }
    }
    for (int i = C-1; i > 0; i--) {
        if (sieve[i] >= C) continue;
        rd[sieve[i]] = i;
    }
}

void solve(int _t)
{
    int c; cin >> c;
    cout << rd[c] << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	prep();
    for (int t = 1; t <= T; t++) solve(t);
}

