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

    int k = 0;
    vector<tuple<int,int>> op;
    for (int i = 0; i < n; i++) {
        int min_idx = min_element(arr.begin()+i, arr.end()) - arr.begin();

        if (min_idx > i) {
            rotate(arr.begin()+i, arr.begin()+min_idx, arr.begin()+min_idx+1);
            op.push_back({i,min_idx});
            k++;
        }
    } 
    cout << k << "\n";
    for (auto a : op) {
        auto [i, j] = a;
        cout << i+1 << " " << j+1 << " " << j-i << "\n";
    }

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
