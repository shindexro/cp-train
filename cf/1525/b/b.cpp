#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sorted(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i-1])
            return false;
    }
    return true;
}

void solve(int _t)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    if (sorted(v))
    {
        cout << "0\n";
    }
    else if (v[0] == 1 || v.back() == n)
    {
        cout << "1\n";
    }
    else if (v[0] == n && v.back() == 1)
    {
        cout << "3\n";
    }
    else
    {
        cout << "2\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
