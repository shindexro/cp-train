#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, k; cin >> n >> k;
    for (int i = 0; i < k - 3; i++) cout << "1 ";
    n -= k - 3;
    if (n % 2 == 1) {
        cout << "1 ";
        cout << n / 2 << " ";
        cout << n / 2 << " ";
    } else if (n % 4 == 2) {
        cout << "2 ";
        cout << n / 2 - 1 << " ";
        cout << n / 2 - 1 << " ";
    } else {
        cout << n / 2 << " ";
        cout << n / 2 / 2 << " ";
        cout << n / 2 / 2 << " ";
    }
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

