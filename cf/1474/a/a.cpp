#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    string b; cin >> b;

    int last = 0;
    for (char c : b) {
        int a;
        if (last == 0 && c == '0')
            a = 1;
        else if (last == 0 && c == '1')
            a = 1;
        else if (last == 1 && c == '0')
            a = 0;
        else if (last == 1 && c == '1')
            a = 1;
        else if (last == 2 && c == '0')
            a = 1;
        else
            a = 0;
        cout << a;
        last = c - '0' + a;
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

