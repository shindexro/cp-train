#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int idx = 0;
    vector<int> ori(n, -1), fin(n);
    for (int i = n - 1; i >= 0; i -= 2) {
        ori[i] = idx;
        fin[idx] = i;
        idx++;
    }
    for (int i = 0; i < n; i++) {
        if (ori[i] != -1)
            continue;

        ori[i] = idx;
        fin[idx] = i;
        idx++;
    }

    bool rev = false;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        int j = ori[i];
        if ((a[j] == b[i]) != rev) {
            ans.push_back(1);
        }
        ans.push_back(i + 1);
        rev = !rev;
    }

    cout << ans.size() << " ";
    for (int i : ans) {
        cout << i << " ";
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
