#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    int n; cin >> n;
    int arr[n];
    map<int,int,greater<int>> freq;
    ll sum = 0;
    int maxToken = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        sum += arr[i];
        maxToken = max(maxToken, arr[i]);
    }

    int needToken = maxToken;
    for (auto [token,f] : freq)
    {
        if (sum >= needToken)
        {
            needToken = token;
            sum -= 1ll * token * f;
        }
        else
            break;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= needToken)
            ans.push_back(i);
    }    
    
    cout << ans.size() << "\n";
    for (int a : ans)
        cout << a+1 << " ";
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
