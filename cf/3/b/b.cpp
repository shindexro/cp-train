#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, v; cin >> n >> v;
    vector<pair<int,int>> boats(n);
    for (int i = 0; i < n; i++) {
        int t, p; cin >> t >> p;
        boats[i] =  {t, p};
    }

    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int a, int b){
            return boats[a].second * 2 / boats[a].first > boats[b].second * 2 / boats[b].first;
            });


    int cap = 0;
    set<int> chosen;
    int lastKayak = -1;
    int cur;
    for (cur = 0; cur < n; cur++) {
        int i = ord[cur];
        if (v <= 0) break;
        if (v < boats[i].first && lastKayak != -1) {
            for (; cur < n && boats[ord[cur]].first == 2; cur++);
            int extra = (cur < n) ? boats[ord[cur]].second : 0;
            if (boats[lastKayak].second + extra > boats[i].second) {
                cap += extra;
                if (cur < n) chosen.insert(ord[cur]);
            } else {
                chosen.erase(lastKayak);
                cap -= boats[lastKayak].second;
                cap += boats[i].second;
                chosen.insert(i);
            }
            break;
        }
        v -= boats[i].first;
        chosen.insert(i);
        cap += boats[i].second;
        if (boats[i].first == 1) lastKayak = i;
    }

    cout  << cap << "\n";
    for (int i : chosen) cout << i + 1 << " ";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

