#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> up(n + 1), down(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> up[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> down[i];
    }

    vector<bool> seen(n + 1);
    seen[n] = true;
    set<int> remain;
    for (int i = 0; i < n; i++) {
        remain.insert(i);
    }

    vector<pii> history(n + 1);
    queue<tuple<int, int, int, int>> q;
    q.push({ n, 0, -1, -1 });
    while (q.size()) {
        auto [depth, step, from, climbed] = q.front();
        q.pop();
        history[depth] = { from, climbed };
        if (depth == 0) {
            break;
        }

        vector<int> to_remove;
        auto it = remain.lower_bound(depth - up[depth]);
        while (it != remain.end() && (*it) <= depth) {
            int peak = *it;
            int to = peak + down[peak];

            if (!seen[to]) {
                seen[to] = true;
                q.push({ to, step + 1, depth, depth - peak });
            }
            to_remove.push_back(peak);
            it++;
        }
        for (int a : to_remove) {
            remain.erase(a);
        }
    }

    if (remain.find(0) != remain.end()) {
        cout << "-1\n";
    } else {
        vector<int> trace;
        int cur = 0;
        while (cur != n) {
            auto [from, climbed] = history[cur];
            trace.push_back(from - climbed);
            cur = from;
        }
        reverse(trace.begin(), trace.end());

        cout << trace.size() << "\n";
        for (int i = 0; i < trace.size(); i++) {
            cout << trace[i] << " ";
        }
        cout << "\n";
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
