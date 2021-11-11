#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool allSame(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[0])
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

    int k = 1;
    vector<int> c(n);
    
    if (allSame(v))
    {
        for (int i = 0; i < n; i++)
            c[i] = 1;
    }
    else
    {
        k = 2;
        for (int i = 0; i < n; i++)
            c[i] = i % 2 + 1;
        
        if (c[0] == c.back() && v[0] != v.back())
        {
            int idx = -1;
            for (int i = 0; i < n-1; i++)
            {
                if (v[i] == v[i+1])
                    idx = i;
            }
            if (idx == -1)
            {
                k = 3;
                c[n-1] = 3;
            }
            else
            {
                c[idx+1] = c[idx];
                for (int i = idx+2; i < n; i++)
                {
                    c[i] = (c[i-1] == 1) ? 2 : 1;
                }
            }
        }
    }


    cout << k << "\n";
    for (int a : c)
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
