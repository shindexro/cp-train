#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr[i] = a;
        freq[a]++;
    }

    for (auto const &p : freq) {
        if (p.second == 1) {
            int idx = find(arr.begin(), arr.end(), p.first) - arr.begin();
            cout << idx + 1 << "\n";
        }
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

