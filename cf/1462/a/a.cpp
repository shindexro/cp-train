#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> ans(n);
    int left = 0, right = n-1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            ans[i] = v[left++];
        else
            ans[i] = v[right--];
    }
    for (int a : ans)
        cout << a << " ";
    cout << "\n";


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
