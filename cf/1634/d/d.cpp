#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;

    int a = 1, b = 2;
    for (int i = 3; i <= n; i += 2) {
        int j = i + 1;
        while (j > n || j == a || j == b || j == i) {
            j--;
        }
        vector<int> cand = { a, b, i, j };
        vector<pair<int, set<int>>> diff;
        int d;

        cout << "? " << cand[0] << " " << cand[1] << " " << cand[2] << "\n"
             << flush;
        cin >> d;
        diff.push_back({ d, { cand[0], cand[1], cand[2] } });

        cout << "? " << cand[0] << " " << cand[1] << " " << cand[3] << "\n"
             << flush;
        cin >> d;
        diff.push_back({ d, { cand[0], cand[1], cand[3] } });

        cout << "? " << cand[0] << " " << cand[2] << " " << cand[3] << "\n"
             << flush;
        cin >> d;
        diff.push_back({ d, { cand[0], cand[2], cand[3] } });

        cout << "? " << cand[3] << " " << cand[1] << " " << cand[2] << "\n"
             << flush;
        cin >> d;
        diff.push_back({ d, { cand[3], cand[1], cand[2] } });

        sort(diff.begin(), diff.end(), greater());
        set<int> next_ab;
        set_intersection(
            diff[0].second.begin(), diff[0].second.end(),
            diff[1].second.begin(), diff[1].second.end(),
            inserter(next_ab, next_ab.begin()));
        a = *(next_ab.begin());
        b = *(++next_ab.begin());
    }
    cout << "! " << a << " " << b << "\n";
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
