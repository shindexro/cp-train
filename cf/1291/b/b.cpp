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

    int right = 0;
    while (right < n) {
        if (v[right] < right) {
            break;
        }
        right++;
    }
    right--;

    int left = n - 1;
    while (left >= 0) {
        if (v[left] < n - 1 - left) {
            break;
        }
        left--;
    }
    left++;

    if (right >= left) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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
