#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n, t; cin >> n >> t;
    map<pair<int,int>, int> memo;
    vector<int> k(t);
    for (int i = 0; i < t; i++)
        cin >> k[i];

    vector<int> ans;
    for (int i = 0; i < t; i++)
    {
        int l = 1, r = n;

        while (l < r)
        {
            int mid = (l + r) / 2;

            int cnt1;
            if (memo.find({l, mid}) != memo.end())
            {
                cnt1 = memo[{l, mid}];
                for (int a : ans)
                    if (l <= a && a <= mid)
                        cnt1++;     // replace with segment tree
            }
            else
            {
                cout << "? " << l << " " << mid << "\n";
                cout.flush();
                cin >> cnt1;
                memo[{l, mid}] = cnt1;
            }
            
            int cnt0 = (mid - l + 1) - cnt1;
            if (k[i] <= cnt0)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
                k[i] -= cnt0;
            }
        }
        ans.push_back(l);
        cout << "! " << l << "\n";
        cout.flush();
    }
    
}

int main()
{
	// ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
