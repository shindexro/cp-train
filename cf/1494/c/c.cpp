#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int maxBox(vector<int>& box, vector<int>& sp)
{
    vector<int> suf(sp.size() + 1);
    for (int i = sp.size() - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + binary_search(box.begin(), box.end(), sp[i]);
    }

    int ans = 0;
    for (int i = 0; i < sp.size(); i++) {
        int r = sp[i];
        auto it = upper_bound(box.begin(), box.end(), r);
        int l = r - (it - box.begin()) + 1;
        int a = i + 1 - (lower_bound(sp.begin(), sp.end(), l) - sp.begin());
        ans = max(ans, a + suf[i + 1]);
    }
    return ans;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<int> v_pos, w_pos, v_neg, w_neg;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            v_neg.push_back(-a);
        } else {
            v_pos.push_back(a);
        }
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            w_neg.push_back(-a);
        } else {
            w_pos.push_back(a);
        }
    }
    reverse(v_neg.begin(), v_neg.end());
    reverse(w_neg.begin(), w_neg.end());

    cout << maxBox(v_pos, w_pos) + maxBox(v_neg, w_neg) << "\n";
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
