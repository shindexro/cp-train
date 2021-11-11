#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    for (int &x : c)
        cin >> x;

    map<int,int> freq;
    for (int x : a)
        freq[x]++;

    ll ans = 0;
    for (int x : c)
        ans += freq[b[x-1]];

    cout << ans;

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

