#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if (n <= 2)
    {
        cout << "0\n";
        return;
    }

    set<int> diff;
    for (int i = 1; i < n; i++)
    {
        diff.insert(a[i] - a[i-1]);
    }
    if (diff.size() == 1)
    {
        cout << "0\n";
        return;
    }
    else if (diff.size() > 2)
    {
        cout << "-1\n";
        return;
    }
    
    vector<int> d(diff.begin(), diff.end());
    sort(d.begin(), d.end());
    int c = d[1], m = d[1] - d[0];

    if (m > mx)
        cout << m << " " << c << "\n";
    else
        cout << "-1\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
