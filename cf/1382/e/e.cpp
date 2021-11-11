#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n, x, y;
    cin >> n >> x >> y;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        freq[a]++;
    }

    priority_queue<pii> pq;
    for (auto& [a, f] : freq) {
        pq.push({ f, a });
    }

    for (int i = 0; i < x; i++) {
        auto& [f, a] = pq.top();
        pq.pop();
        if (f > 0) {
            pq.push({ f - 1, a });
        }
    }

    int z = y - x;
    priority_queue<pii, vector<pii>, greater<pii>> pq2;
    priority_queue<pii> pq3;
    while (pq.size()) {
        auto& [f, a] = pq.top();
        pq.pop();
        pq2.push({ f, a });
        pq3.push({ f, a });
    }

    vector<int> colors;
    for (int i = 0; i < z; i++) {
        auto& [f, a] = pq2.top();
        pq2.pop();
        colors.push_back(a);
        if (f > 0) {
            pq2.push({ f - 1, a });
        }
    }

    for (int i = 0; i < z; i++) {
        int c = colors[i];
        auto& [f, a] = pq3.top();
        pq3.pop();
        if (a == c) {
            if (pq.size() == 0) {
                cout << "NO\n";
                return;
            }

            auto& [f2, a2] = pq3.top();
            pq3.pop();
            pq3.push({ f, a });
            pq3.push({ f2 - 1, a2 });

        } else {
            pq3.push({ f - 1, a });
        }
    }
    cout << "YES\n";
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
