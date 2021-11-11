#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    map<int,int,greater<int>> freq;
    for (int i = 0; i < n*2; i++)
    {
        int a; cin >> a;
        freq[a]++;
    }
    unordered_set<int> xs;
    auto [a,f] = *freq.begin(); 
    for (auto it = (freq[a] > 1) ? freq.begin() : ++freq.begin();
              it != freq.end(); it++)
    {
        auto [b,f] = *it;
        xs.insert(a + b);
    }

    while (xs.size())
    {
        int initX = *xs.begin();
        int x = initX;
        vector<int> op1, op2;
        map<int,int,greater<int>> remain(freq.begin(), freq.end());
        while (remain.size())
        {
            auto [a,f] = *remain.begin();
            int b = x - a;
            if (remain.find(b) != remain.end())
            {
                remain[a]--;
                remain[b]--;
                if (remain[a] == 0) remain.erase(a);
                if (remain[b] == 0) remain.erase(b);
                op1.push_back(a);
                op2.push_back(b);
                x = a;
            }
            else
            {
                break;
            }
        }

        if (remain.size() == 0)
        {
            cout << "YES\n";
            cout << initX << "\n";
            for (int i = 0; i < n; i++)
            {
                cout << op1[i] << " " << op2[i] << "\n";
            }
            return;
        }
        xs.erase(initX);
    }
    cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

