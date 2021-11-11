#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    ll n, k; cin >> n >> k;
    ll maxK = 1ll << (n-1);
    if (n < 64 && k > maxK)
    {
        cout << "-1\n";
        return;
    }

    vector<int> seg;
    int remain = n;
    k--;
    while (k > 0)
    {
        int cnt = 1;
        while (k & 1)
        {
            cnt++;
            k >>= 1;
        }
        k >>= 1;
        remain -= cnt;
        seg.push_back(cnt);
    }
    while (remain--)
        seg.push_back(1);
    reverse(seg.begin(), seg.end());

    vector<int> ans(n);
    int cur = 1, idx = 0;
    for (int s : seg)
    {
        for (int i = 0; i < s; i++)
        {
            ans[idx + s - i - 1] = cur;
            cur++;
        }
        idx += s;
    }

    for (int a : ans)
        cout << a << " ";
    cout << "\n";
}

int main()
{
	//ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
