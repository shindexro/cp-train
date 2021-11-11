#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    vector<int> as(n), bs(n);
    for (int i = 0; i < n; i++) cin >> as[i];
    for (int i = 0; i < n; i++) cin >> bs[i];

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    for (int a : as) cout << a << " ";
    cout << "\n";
    for (int a : bs) cout << a << " ";
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

