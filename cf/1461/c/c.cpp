#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, m; cin >> n >> m;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) cin >> perm[i];
    vector<pair<int,double>> pre(m);
    for (int i = 0; i < m; i++)
    {
        int a; double b; cin >> a >> b;
        pre[i] = {a, b};
    }

    int sortedSuf = 0;
    for (int i = n-1; i >= 0 && perm[i] == i+1; i--)
        sortedSuf++;

    if (sortedSuf == n)
    {
        cout << "1\n";
        return;
    }

    int threshold = n - sortedSuf;
    double failProb = 1;
    for (auto [p,prob] : pre)
    {
        if (p >= threshold)
            failProb *= (1 - prob);
    }
    cout << setprecision(15) << 1 - failProb << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
