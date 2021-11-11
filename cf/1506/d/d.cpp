#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map
typedef long long ll;
typedef pair<int, int> pii;

void solve(int t)
{
	int n;
	cin >> n;
	umap<int, int> freq;
	freq.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		freq[a]++;
	}

	priority_queue<int> pq;
	for (auto const& p : freq) pq.push(p.second);

	int sz = n;
	while (pq.size() > 1)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		sz -= 2;
		if (a > 1) pq.push(a - 1);
		if (b > 1) pq.push(b - 1);
	}

    cout << sz << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("1506D_case.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
