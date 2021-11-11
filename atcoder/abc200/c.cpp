#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll ans = 0;
    map<int,int> freq;
    for (int a : v)
    {
        int r = a % 200;
        ans += freq[r];
        freq[r]++;
    }
    cout << ans;
        
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

