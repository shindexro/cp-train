#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    map<int,int> freq;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        freq[a]++;
    }

    map<int,int> ffreq;
    int t = 0;
    for (auto [k,v] : freq)
    {
        ffreq[v]++;
        t++;
    }

    int prevC = 0;
    int ans = n, cur = n;
    int right = t;
    for (auto [k,v] : ffreq)
    {
        int diff = k - prevC;
        cur -= right * diff;
        cur += ffreq[prevC] * prevC;
        ans = min(ans, cur);
        prevC = k;
        right -= v;
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
