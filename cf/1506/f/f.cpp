#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map
typedef long long ll;
typedef pair<int, int> pii;

void solve(int t)
{
	int n;
	cin >> n;
	vector<pii> points(n + 1);
	for (int i = 0; i < n; i++) cin >> points[i].first;
	for (int i = 0; i < n; i++) cin >> points[i].second;
	points[n] = pii(1,1);
	sort(points.begin(), points.end());

	ll cost = 0;
	for (int i = 0; i < n; i++)
	{
		pii p1 = points[i], p2 = points[i + 1];
		int rmoves = p2.second - p1.second;
		int lmoves = p2.first - p1.first - rmoves;

		if (lmoves == 0 && ((p1.first + p1.second) & 1) == 0)
		{
			cost += rmoves;
		}
		cost += (((p1.first + p1.second) & 1) == 0) ? lmoves / 2 : (lmoves + 1) / 2;
	}

	cout << cost << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
		solve(t);
}
