#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-7;

bool checkAri(vector<int> a)
{
    int d = a[1] - a[0];
    for (int i = 2; i < a.size(); i++)
    {
        if (a[i] - a[i-1] != d)
            return false;
    }
    return true;
}

bool checkGeo(vector<int> a)
{
    if (a[1] * a[1] % a[0] != 0)
        return false;

    for (int i = 2; i < a.size(); i++)
    {
        int t = a[i] * a[1];
        if (t % a[0] != 0 || a[i] != a[i-1] * a[1] / a[0])
            return false;
    }
    return true;
}


void solve(int _t)
{
    vector<int> a(4);
    for (int i = 0; i < 4; i++)
        cin >> a[i];

    if (checkAri(a))
    {
        cout << a[3] + a[1] - a[0] << "\n";
        return;
    }
    
    if (checkGeo(a))
    {
        int t = a[3] * a[1];
        if (t % a[0] != 0)
            cout << "42\n";
        else
            cout << t / a[0] << "\n";
    }
    else
    {
        cout << "42\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
