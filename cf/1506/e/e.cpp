#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map
#define uset unordered_set
typedef long long ll;

void solve(int t)
{
    int n;
	cin >> n;
	vector<int> q(n);
	for (int i = 0; i < n; i++) cin >> q[i];

	set<int> unused;
	for (int i = 0; i < n; i++) unused.insert(i + 1);

	vector<int> pmin(n);
	vector<int> pmax(n);
	pmin[0] = pmax[0] = q[0];
	unused.erase(q[0]);
	for (int i = 1; i < n; i++) if (q[i] != q[i - 1])
	{
		pmin[i] = pmax[i] = q[i];
		unused.erase(q[i]);
	}

	int i = 0;
	for (int a : unused)
	{
		while (pmin[i] != 0) i++;
		pmin[i] = a;
	}

	for (i = 0; i < n; i++) if (pmax[i] == 0)
	{
		auto it = unused.lower_bound(q[i]);
		it--;
		pmax[i] = *it;
		unused.erase(it);
	}

	for (int a : pmin) cout << a << " ";
	cout << "\n";
	for (int a : pmax) cout << a << " ";
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
