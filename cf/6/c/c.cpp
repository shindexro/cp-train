#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int a = 0, b = n - 1;
    while (a + 1 < b) {
        if (arr[a] <= arr[b]) {
            arr[b] -= arr[a];
            a++;
        } else {
            arr[a] -= arr[b];
            b--;
        }
    }
    cout << a + 1 << " " << n - a - 1;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

