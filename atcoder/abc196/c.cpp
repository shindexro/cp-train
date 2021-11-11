#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    string n; cin >> n;

    ll ans = 0;
    if (n.size() % 2 == 1)
    {
        for (int i = 0; i < n.size() / 2; i++)
            ans = ans * 10 + 9;
    }
    else
    {
        string fst = n.substr(0, n.size() / 2);
        string snd = n.substr(n.size() / 2);
        int a = stoi(fst);
        int b = stoi(snd);
        if (a <= b)
            ans = a;
        else
            ans = a - 1;
    }
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

