#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
   int n, W; cin >> n >> W;
   vector<int> arr(n);
   for (int i = 0; i < n; i++) cin >> arr[i];
   sort(arr.rbegin(), arr.rend());

   map<int, int> spaceFreq;
   int ans = 0;
   for (int a : arr) {
       auto it = spaceFreq.lower_bound(a);
       if (it != spaceFreq.end()) {
           int k = it->first;
           spaceFreq[k]--;
           if (spaceFreq[k] == 0)
               spaceFreq.erase(it);
           spaceFreq[k - a]++;
       } else {
           ans++;
           spaceFreq[W - a]++;
       }
   }
   cout << ans << "\n";   
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

