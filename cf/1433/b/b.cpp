#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int left = 0, right = n-1;
    while (left < n && v[left] == 0)
        left++;
    while (right >= 0 && v[right] == 0)
        right--;

    int ans = 0;
    for (int i = left; i < right; i++)
    {
        if (v[i] == 0)
            ans++;
    }
    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
