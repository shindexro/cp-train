#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

set<int> ans;

void subseq(vector<int>& v, int i, int n, int sum, int last)
{
    if (i == n) {
        ans.insert(sum);
        return;
    }

    if (v[i] > last) {
        subseq(v, i + 1, n, sum ^ v[i], v[i]);
    }
    subseq(v, i + 1, n, sum, last);
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    subseq(v, 0, n, 0, -1);

    cout << ans.size() << "\n";
    for (int a : ans) {
        cout << a << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
