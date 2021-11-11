#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    vector<int> unused;
    int cur = 0;
    for (int a : arr) {
        if (a == cur) {
            cout << a << " ";
            cur++;
        } else {
            unused.push_back(a);
        }
    }
    for (int a : unused) cout  << a << " ";
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

