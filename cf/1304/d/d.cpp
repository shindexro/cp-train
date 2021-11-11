#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> ansShort(n);
    vector<int> ansLong(n);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '<') {
            ansShort[i] = ansLong[i] = -1;
        }
    }
    ansShort[0] = ansLong[0] = -1;

    int cur = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ansShort[i] == 0)
            ansShort[i] = cur++;
    }
    cur = n;
    for (int i = 0; i < n; i++) {
        if (ansShort[i] != -1) {
            for (int j = i - 1; j >= 0 && ansShort[j] == -1; j--)
                ansShort[j] = cur--;
        }
    }
    for (int i = n - 1; i >= 0 && ansShort[i] == -1; i--)
        ansShort[i] = cur--;


    cur = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ansLong[i] == 0)
            ansLong[i] = cur++;
    }
    
    for (int i = 0; i < n; i++)
        if (ansLong[i] == -1)
            ansLong[i] = cur++;

    for (int a : ansShort) cout << a << " ";
    cout << "\n";

    for (int a : ansLong) cout << a << " ";
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

