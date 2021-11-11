#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

struct VectorHash {
    size_t operator()(const vector<int> &v) const {
        size_t seed = v.size();
        for (int a : v) {
            seed ^= a + 0x9e3779b9 + (seed << 6) +  (seed >> 2);
        }
        return seed;
    }
};

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> max_build(n);

    vector<vector<int>> slots(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        slots[i] = vector<int>(c);
        for (int j = 0; j < c; j++) {
            cin >> slots[i][j];
        }
        max_build[i] = c-1;
    }

    int m; 
    cin >> m;
    unordered_set<vector<int>, VectorHash> banned;
    for (int i = 0; i < m; i++) {
        vector<int> build(n);
        for (int j = 0; j < n; j++) {
            cin >> build[j];
            build[j]--;
        }
        banned.insert(build);
    }

    auto cmp = [&](vector<int> &a, vector<int> &b) -> bool {
        int acost = 0, bcost = 0;
        for (int i = 0; i < n; i++)
            acost += slots[i][a[i]];
        for (int i = 0; i < n; i++)
            bcost += slots[i][b[i]];
        return acost < bcost;
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> builds(cmp);
    unordered_set<vector<int>, VectorHash> visited;

    builds.push(max_build);
    visited.insert(max_build);

    int cnt = 1;
    while (builds.size()) {
        vector<int> build = builds.top();
        builds.pop();

        if (banned.find(build) == banned.end()) {
            for (int i : build)
                cout << i+1 << " ";
            cout << "\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            if (build[i] > 0) {
                vector<int> nextBuild(build);
                nextBuild[i]--;
                if (visited.find(nextBuild) == visited.end()) {
                    builds.push(nextBuild);
                    visited.insert(nextBuild);
                }
            }
        }
        cnt++;
    }
    // should not reach
    assert(false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
