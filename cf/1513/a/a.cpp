#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n, k; cin >> n >> k;
    
    if (k > (n-1)/2) {
        cout << "-1\n";
        return;
    }
    
    vector<int> arr(n);
    for (int i=0; i<n; i++) arr[i] = i;

    for (int i=2; i<n && k>0; i+=2, k--) {
        swap(arr[i], arr[i-1]);
    }
    
    for (int a:arr) cout << a+1 << " ";
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

