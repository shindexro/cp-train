#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    string a, b; cin >> a >> b;

    int a1 = count(a.begin(), a.end(), '1');
    bool flipped = false;
    for (int i = n-1; i >= 0; i--)
    {
        int len = i + 1;
        if ((!flipped && a[i] != b[i]) || (flipped && a[i] == b[i]))
        {
            if (a1 != len - a1)
            {
                cout << "NO\n";
                return;
            }
            flipped = !flipped;
        }
        if (a[i] == '1')
            a1--;
    }
    cout << "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

