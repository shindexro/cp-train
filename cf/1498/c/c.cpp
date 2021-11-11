#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, k; cin >> n >> k;
    int mod = (int)1e9 + 7;

    vector<int> emit(n);
    emit[0] = 1;
    int ans = k > 1;
    for (int d = 0; d < k; d++) {
        int total = 0;
        vector<int> nextEmit(n);
        for (int i = 0; i < n; i++) {
            nextEmit[n - i - 1] = total;
            total = (total + emit[i]) % mod;
        }
        ans = (ans + total) % mod;
        emit = nextEmit;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

