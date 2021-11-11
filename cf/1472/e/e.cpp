#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<pair<int,int>> fds(n);
    vector<int> ord(n);
    for (int i = 0; i < n; i++)
    {
        ord[i] = i;
        cin >> fds[i].first >> fds[i].second;
        if (fds[i].first < fds[i].second)
            swap(fds[i].first, fds[i].second);
    }
    
    sort(ord.begin(), ord.end(), [&](int a, int b) { return fds[a] < fds[b]; });
    vector<int> ans(n);
    int curFst = fds[ord[0]].first;
    int lastMinIdx = -1, curMinIdx = ord[0];
    for (int i = 0; i < n; i++)
    {
        int idx = ord[i];
        auto f = fds[idx];
        if (f.first != curFst)
        {
            curFst = f.first;
            lastMinIdx = curMinIdx;
        }
        if (lastMinIdx != -1 && fds[lastMinIdx].second < f.second)
            ans[idx] = lastMinIdx + 1;
        else
            ans[idx] = -1;

        if (f.second < fds[curMinIdx].second)
            curMinIdx = idx;
    }

    for (int a : ans)
        cout << a << " ";
    cout << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
