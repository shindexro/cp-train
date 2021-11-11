#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline bool brute(vector<int> &v, vector<int> &indices)
{
    for (int a : indices)
        for (int b : indices)
            for (int c : indices)
                for (int d : indices)
                    if (a != b && a != c && a != d
                            && b != c && b != d && c != d
                            && v[a] + v[b] == v[c] + v[d])
                    {
                        cout << "YES\n";
                        cout << a + 1 << " ";
                        cout << b + 1 << " ";
                        cout << c + 1 << " ";
                        cout << d + 1 << " ";
                        return true;
                    }
    return false;
}

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int &a : v)
        cin >> a;
    
    vector<vector<int>> seen(5e6 + 7);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = v[i] + v[j];
            seen[sum].push_back(i);
            seen[sum].push_back(j);

            if (seen[sum].size() >= 8)
            {
                brute(v, seen[sum]);
                return;
            }
        }
    }
    for (vector<int> s : seen)
    {
        if (brute(v, s))
            return;
    }
    cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
