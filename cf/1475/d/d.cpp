#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, m; cin >> n >> m;
    vector<int> appMem(n);
    vector<int> appConv(n);
    ll totalAppMem = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        totalAppMem += a;
        appMem[i] = a;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> appConv[i];
    }

    if (totalAppMem < m)
    {
        cout << "-1\n";
        return;
    }

    vector<int> reg, imp;
    for (int i = 0; i < n; i++)
    {
        if (appConv[i] == 1)
            reg.push_back(appMem[i]);
        else
            imp.push_back(appMem[i]);
    }
    sort(reg.rbegin(), reg.rend());
    sort(imp.rbegin(), imp.rend());
    if (reg.size() % 2 == 1)
        reg.push_back(0);

    int ans = 0;
    int regIdx = 0, impIdx = 0;
    
    while (m > 0)
    {
        if (impIdx >= imp.size() ||
                (regIdx+1 < reg.size() && reg[regIdx] + reg[regIdx+1] > imp[impIdx]))
        {
            m -= reg[regIdx] + reg[regIdx+1];
            regIdx += 2;
        } else {
            m -= imp[impIdx];
            impIdx++;
        }
        ans += 2;
    }

    if ((regIdx-1 >= 0 && m + reg[regIdx-1] <= 0) ||
            (impIdx-1 >= 0 && regIdx < reg.size() && m + imp[impIdx-1] - reg[regIdx] <= 0))
    {
        ans--;
    }

    cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
