#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n, k; cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int fst = 0;
    while (k && fst < n)
    {
        if (arr[fst])
        {
            arr[fst]--;
            arr[n-1]++;
            k--;
        }
        else
        {
            fst++;
        }
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
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
