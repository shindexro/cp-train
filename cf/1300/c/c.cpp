#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0, dup = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dup |= sum & arr[i];
        sum |= arr[i];
    }

    int first = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int f = (arr[i] | dup) - dup;
        if (f > max) {
            first = i;
            max = f;
        }
    }

    cout << arr[first] << " ";
    for (int i = 0; i < n; i++) if (i != first) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

