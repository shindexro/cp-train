#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    int as[n];
    for (int i = 0; i < n; i++) cin >> as[i];

    int preMin[n], sufMin[n];
    preMin[0] = as[0];
    sufMin[n-1] = as[n-1];
    for (int i = 1; i < n; i++)
    {
        preMin[i] = min(preMin[i-1], as[i]);
        sufMin[n-i-1] = min(sufMin[n-i], as[n-i-1]);
    }

    for (int i = 1; i < n-1; i++)
    {
        if (preMin[i-1] + sufMin[i+1] < as[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
