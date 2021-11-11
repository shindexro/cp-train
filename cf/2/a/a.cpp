#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    unordered_map<string, int> finalScore;
    vector<pair<string, int>> history(n);

    for (int i = 0; i < n; i++) {
        string p;
        int gain;
        cin >> p >> gain;
        history[i] = {p, gain};
        finalScore[p] += gain;
    }

    int mx = 0;
    for (auto p : finalScore) {
        mx = max(mx, p.second);
    }

    unordered_map<string, int> score;
    for (auto p : history) {
        score[p.first] += p.second;
        if (score[p.first] >= mx && finalScore[p.first] == mx) {
            cout << p.first << "\n";
            return;
        }
    }

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

