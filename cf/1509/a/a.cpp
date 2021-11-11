#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> evens, odds;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a % 2 == 0) evens.push_back(a);
        else odds.push_back(a);
    }

    for (int a : evens) cout << a << " ";
    for (int a : odds) cout << a << " ";
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

