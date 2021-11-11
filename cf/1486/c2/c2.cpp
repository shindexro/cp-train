#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

map<pii, int> memo;

int query(int left, int right)
{
    if (memo.find({ left, right }) != memo.end()) {
        return memo[{ left, right }];
    }

    if (left >= right) {
        return -1;
    }

    int res;
    cout << "? " << left << " " << right << "\n";
    cin >> res;

    memo[{ left, right }] = res;
    return res;
}

void solve(int tc)
{
    int n;
    cin >> n;

    int left = 1, right = n;
    int res, res2;
    while (left < right) {
        res = query(left, right);

        int mid = (left + right) / 2;
        if (res <= mid) {
            res2 = query(left, mid);
            if (res == res2) {
                right = mid;
            } else {
                left = mid + 1;
            }
        } else {
            res2 = query(mid + 1, right);
            if (res == res2) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }
    cout << "! " << left << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
