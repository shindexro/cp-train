#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, w, h; cin >> n >> w >> h;
    vector<pair<int, int>> envs;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        envs.push_back({a, b});
    }

    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int a, int b){ return envs[a] < envs[b]; });

    int maxChain = 0, chainTail = 0;
    vector<int> chain(n), prev(n);
    for (int i = 0; i < n; i++) {
        auto env1 = envs[ord[i]];
        if (env1.first <= w || env1.second <= h) continue;
        chain[i] = 1;
        for (int j = 0; j < i; j++) {
            auto env2 = envs[ord[j]];
            if (env2.first <= w || env2.second <= h) continue;
            if (env1.first > env2.first && 
                    env1.second > env2.second && chain[i] < chain[j] + 1) {
                chain[i] = chain[j] + 1;
                prev[i] = j;
            }
        }
        if (chain[i] > maxChain) {
            maxChain = chain[i];
            chainTail = i;
        }
    }

    vector<int> ans(maxChain);
    for (int i = maxChain - 1; i >= 0; i--) {
        ans[i] = ord[chainTail];
        chainTail = prev[chainTail];
    }

    cout << maxChain << "\n";
    for (int a : ans) cout << a + 1 << " ";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

