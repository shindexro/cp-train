#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 65;
ll combin[N][N];

void build()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                combin[i][j] = 1;
            else
                combin[i][j] = combin[i-1][j-1] + combin[i-1][j];
        }
    }
}

void solve(int _t)
{
    ll a, b, k; cin >> a >> b >> k;
    string s = "";

    while (a || b)
    {
        ll fstA = combin[a+b-1][b];
        if (k <= fstA)
        {
            s += 'a';
            a--;
        }
        else
        {
            s += 'b';
            b--;
            k -= fstA;
        }
    }

    cout << s;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    build();
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

