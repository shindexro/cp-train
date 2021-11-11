#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.rbegin(), arr.rend());
    ll alice = 0, bob = 0;
    bool aliceTurn = true;
    for (int a : arr)
    {
        if (aliceTurn && a % 2 == 0)
            alice += a;
        else if (!aliceTurn && a % 2 == 1)
            bob += a;
        aliceTurn = !aliceTurn;
    }
    if (alice > bob)
        cout << "Alice\n";
    else if (alice < bob)
        cout << "Bob\n";
    else
        cout << "Tie\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
