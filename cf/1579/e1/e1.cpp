#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(int tc)
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;

    int mn = n+1;
    deque<int> ans;

    for (int a : arr) {
        if (a < mn) {
            ans.push_front(a);
            mn = a;
        } else {
            ans.push_back(a);
        }
    }

    for (int a : ans)
        cout << a << " ";
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
        solve(t);
}
