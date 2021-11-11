#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, d; cin >> n >> d;
    vector<int> arr(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    if (mx <= d) {
        cout << "YES\n";
        return;
    }

    int mn = d + 1;
    for (int a : arr) {
        if (a + mn <= d) {
            cout << "YES\n";
            return;
        }
        mn = min(mn, a);
    }
    cout << "NO\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

