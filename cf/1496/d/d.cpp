#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> slope;
    bool up = true;
    int len = 0;
    for (int i = 1; i < n; i++) {
        if ((up && v[i] < v[i - 1]) || (!up && v[i] > v[i - 1])) {
            up = !up;
            slope.push_back(len);
            len = 1;
        } else {
            len++;
        }
    }
    slope.push_back(len);
    slope.push_back(0);
    slope.push_back(0);

    int ans = 0;
    int mx = *max_element(slope.begin(), slope.end());
    bool peak = false;
    for (int i = 0; i + 1 < slope.size(); i += 2) {
        int l = slope[i], r = slope[i + 1];
        if (l > r) {
            swap(l, r);
        }

        if (r < mx) {
            continue;
        }
        if (peak) {
            ans = 0;
            break;
        }
        peak = true;

        if (r % 2 == 0 && r - 1 < l) {
            ans++;
        }
    }
    cout << ans << "\n";
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
