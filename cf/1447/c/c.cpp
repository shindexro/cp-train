#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    ll n, w; cin >> n >> w;
    vector<ll> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;

    sort(ord.begin(), ord.end(), [&](int a, int b){ return weights[a] > weights[b]; });
    
    ll curW = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int idx = ord[i];
        int a = weights[idx];
        if (a > w) continue;
        curW += a;
        ans.push_back(idx);
        if (curW >= (w+1)/2) break;
    }

    if (curW >= (w+1)/2)
    {
        cout << ans.size() << "\n";
        for (int a : ans) cout << a + 1 << " ";
        cout << "\n";
    }
    else
        cout << "-1\n";


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
