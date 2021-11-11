#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    map<int,int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[v[i] - i]++;
    }

    ll ans = 0;
    for (auto [a,b] : freq)
    {
        if (b >= 2)
            ans += 1ll * b * (b-1) / 2;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
