#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, l, r, s; cin >> n >> l >> r >> s;
    r--; l--;
    int d = r - l;
    int mx = (n + n - d) * (d + 1) / 2;
    int mn = (2 + d) * (d + 1) / 2;
    
    vector<int> arr(n);
    vector<bool> used(n+1);
    if (mn <= s && s <= mx) {
        s -= mn;
        int maxAdd = n-d-1;
        for (int i = 0; i <= d; i++) {
            int add = min(maxAdd, s);
            int val = d-i+1 + add;
            arr[l+i] = val;
            used[val] = true;
            s -= add;
        }
        for (int i=0, j=1; i < n; i++) {
            if (arr[i] != 0) continue;
            while (used[j]) j++;
            arr[i] = j;
            used[j] = true;
        }

        for (int a : arr) cout << a << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

