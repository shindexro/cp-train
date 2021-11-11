#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n), rev(n + 1);
    set<int, greater<int>> rem;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        rev[v[i]] = i;
        rem.insert(v[i]);
    }

    vector<int> ans;
    int last = n;
    while (last) {
        int mx = *rem.begin();
        int idx = rev[mx];
        for (int i = idx; i < last; i++) {
            ans.push_back(v[i]);
            rem.erase(v[i]);
        }
        last = idx;
    }

    for (int a : ans) {
        cout << a << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
