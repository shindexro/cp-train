#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, q; cin >> n >> q;
    vector<int> topColor(53);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (topColor[a] == 0) topColor[a] = i+1;
    }
    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        cout << topColor[a] << " ";
        for (int j = 0; j < 53; j++)
            if (topColor[j] < topColor[a])
                topColor[j]++;
        topColor[a] = 1;
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

